#ifndef CB_VISITOR
#define CB_VISITOR

#include<map>
#include<string>
#include<stack>
#include<list>

#include<antlr4-runtime/antlr4-runtime.h>
#include"antlr/BasicLexer.h"
#include"antlr/BasicParser.h"
#include"antlr/BasicBaseVisitor.h"

#include<llvm/IR/DerivedTypes.h>
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/Function.h>
#include<llvm/IR/InstrTypes.h>
#include<llvm/IR/Instruction.h>
#include<llvm/IR/LLVMContext.h>
#include<llvm/IR/Module.h>
#include<llvm/IR/Verifier.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Target/TargetMachine.h>
#include<llvm/ExecutionEngine/JITSymbol.h>
#include<llvm/ExecutionEngine/Orc/LLJIT.h>
#include<llvm/ExecutionEngine/Orc/CompileUtils.h>
#include<llvm/ExecutionEngine/Orc/Core.h>
#include<llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h>
#include<llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include<llvm/ExecutionEngine/Orc/IRCompileLayer.h>
#include<llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#include<llvm/ExecutionEngine/SectionMemoryManager.h>
#include<llvm/IR/DataLayout.h>
#include<llvm/ExecutionEngine/ExecutionEngine.h>
using namespace llvm;
using namespace std;
using namespace antlr4;

string strToLower(string str){
    transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
    return str;
}

class TypeTable{
    LLVMContext& context;
    llvm::Module& mod;
    map<string,llvm::Type*> builtInTypes;
public:
    TypeTable(llvm::Module& mod,LLVMContext& context):mod(mod),context(context){
        builtInTypes.operator=({
               {"integer",Type::getInt32Ty(context)},
               {"single",Type::getFloatTy(context)},
               {"double",Type::getDoubleTy(context)},
               {"boolean",Type::getInt1Ty(context)},
               {"long",Type::getInt64Ty(context)},
               {"byte",Type::getInt8Ty(context)}
       });
    }

    Type* find(Token* type){
        string name = strToLower(type->getText());
        auto builtIn = builtInTypes.find(name);
        if(builtIn!=builtInTypes.end())return builtIn->second;
        auto structure = mod.getTypeByName(name.c_str());
        if(structure!=nullptr)return structure;
        //TODO: 报告找不到类型
        return nullptr;
    }

};

class InvalidSyntax{
    int row,column;
public:
    InvalidSyntax(antlr4::Token* token){
        row=token->getLine();
        column=token->getCharPositionInLine();
    }
};

class ArgumentInfo{
public:
    string name;
    Type* type;
    antlr4::tree::ParseTree* initial;

    ArgumentInfo(BasicParser::VariableContext *ctx,TypeTable& typeTable){
        name=strToLower(ctx->name->getText());
        type=typeTable.find(ctx->type->ID()->getSymbol());
        initial=ctx->initial;
    }
};

class StackFrame{
    int index=0;
    stack<string> layers;
public:
    llvm::Function* function;
    StackFrame(llvm::Function* function){
        this->function=function;
    }
    using VarTable = map<string,AllocaInst*>;
    VarTable varTable;
    void BeginLayer(string prefix){
        layers.push(prefix + "_" + std::to_string(index) + "_");
        index++;
    }

    string getBlockName(string suffix){
        return layers.top()+suffix;
    }

    void EndLayer(){
        layers.pop();
    }

};

class Visitor:public BasicBaseVisitor{
    llvm::Module& mod;
    LLVMContext& context;
    TypeTable typeTable;
    stack<StackFrame> frame;
    IRBuilder<> builder;
public:

    Visitor(llvm::Module& m,LLVMContext& ctx):context(ctx),mod(m),typeTable(m,ctx),builder(ctx){

    }

    //=========================================== utility =================================================
    void visitBlock(vector<BasicParser::LineContext*>& block){
        for(auto& line:block)visit(line);
    }
    //=========================================== flow-control =================================================

    virtual antlrcpp::Any visitDoWhile(BasicParser::DoWhileContext *ctx) override {
        frame.top().BeginLayer("Loop");
        auto condition = visit(ctx->exp()).as<Value*>();
        auto condBlock = BasicBlock::Create(context,frame.top().getBlockName("LoopCondition"),frame.top().function);
        auto loop = BasicBlock::Create(context,frame.top().getBlockName("Loop"),frame.top().function);
        auto loopEnd = BasicBlock::Create(context,frame.top().getBlockName("LoopEnd"),frame.top().function);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(condBlock);
        builder.CreateCondBr(condition,loop,loopEnd);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.top().EndLayer();
        return nullptr;
    }

    virtual antlrcpp::Any visitDoUntil(BasicParser::DoUntilContext *ctx) override {
        frame.top().BeginLayer("Loop");
        auto condition = visit(ctx->exp()).as<Value*>();
        auto condBlock = BasicBlock::Create(context,frame.top().getBlockName("LoopCondition"),frame.top().function);
        auto loop = BasicBlock::Create(context,frame.top().getBlockName("Loop"),frame.top().function);
        auto loopEnd = BasicBlock::Create(context,frame.top().getBlockName("LoopEnd"),frame.top().function);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(condBlock);
        builder.CreateCondBr(condition,loopEnd,loop);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.top().EndLayer();
        return nullptr;
    }

    virtual antlrcpp::Any visitLoopUntil(BasicParser::LoopUntilContext *ctx) override {
        frame.top().BeginLayer("Loop");
        auto condition = visit(ctx->exp()).as<Value*>();
        auto loop = BasicBlock::Create(context,frame.top().getBlockName("Loop"),frame.top().function);
        auto condBlock = BasicBlock::Create(context,frame.top().getBlockName("LoopCondition"),frame.top().function);
        auto loopEnd = BasicBlock::Create(context,frame.top().getBlockName("LoopEnd"),frame.top().function);
        builder.CreateBr(loop);
        builder.SetInsertPoint(condBlock);
        builder.CreateCondBr(condition,loopEnd,loop);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.top().EndLayer();
        return nullptr;
    }

    virtual antlrcpp::Any visitLoopWhile(BasicParser::LoopWhileContext *ctx) override {
        frame.top().BeginLayer("Loop");
        auto condition = visit(ctx->exp()).as<Value*>();
        auto loop = BasicBlock::Create(context,frame.top().getBlockName("Loop"),frame.top().function);
        auto condBlock = BasicBlock::Create(context,frame.top().getBlockName("LoopCondition"),frame.top().function);
        auto loopEnd = BasicBlock::Create(context,frame.top().getBlockName("LoopEnd"),frame.top().function);
        builder.CreateBr(loop);
        builder.SetInsertPoint(condBlock);
        builder.CreateCondBr(condition,loop,loopEnd);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.top().EndLayer();
        return nullptr;
    }

    virtual antlrcpp::Any visitWhileWend(BasicParser::WhileWendContext *ctx) override {
        frame.top().BeginLayer("Loop");
        auto condition = visit(ctx->exp()).as<Value*>();
        auto condBlock = BasicBlock::Create(context,frame.top().getBlockName("LoopCondition"),frame.top().function);
        auto loop = BasicBlock::Create(context,frame.top().getBlockName("Loop"),frame.top().function);
        auto loopEnd = BasicBlock::Create(context,frame.top().getBlockName("LoopEnd"),frame.top().function);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(condBlock);
        builder.CreateCondBr(condition,loop,loopEnd);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.top().EndLayer();
        return nullptr;
    }

    virtual antlrcpp::Any visitSingleLineIf(BasicParser::SingleLineIfContext *ctx) override {
        return nullptr;
    }

    virtual antlrcpp::Any visitMutiLineIf(BasicParser::MutiLineIfContext *ctx) override {
        list<BasicBlock*> trueBlocks;
        for(auto c:ctx->ifBlock())trueBlocks.push_back(visit(c).as<BasicBlock*>());
        for(auto b:ctx->elseBlock)visit(b);
        auto endBlock = BasicBlock::Create(context,frame.top().getBlockName("IF_End"),frame.top().function);
        builder.CreateBr(endBlock);
        for(auto b:trueBlocks){
            builder.SetInsertPoint(b);
            builder.CreateBr(endBlock);
        }
        builder.SetInsertPoint(endBlock);
        return nullptr;
    }

    virtual antlrcpp::Any visitIfBlock(BasicParser::IfBlockContext *ctx) override {
        frame.top().BeginLayer("If");
        Value* cond = visit(ctx->exp()).as<Value*>();
        auto trueBlock = BasicBlock::Create(context,frame.top().getBlockName("True"),frame.top().function);
        auto falseBlock = BasicBlock::Create(context,frame.top().getBlockName("False"),frame.top().function);
        builder.CreateCondBr(cond,trueBlock,falseBlock);
        builder.SetInsertPoint(trueBlock);
        visitBlock(ctx->block);
        builder.SetInsertPoint(falseBlock);
        frame.top().EndLayer();
        return trueBlock;
    }

    //============================================ declare ====================================================


    virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *ctx) override {
        for(auto arg:ctx->variable()){
            auto info = visit(arg).as<ArgumentInfo>();
            auto ptr = builder.CreateAlloca(info.type,nullptr,info.name.c_str());
            frame.top().varTable.insert(make_pair(info.name,ptr));
            if(info.initial!=nullptr){
                //TODO: 写一个Variant容器解决Any无法转换类型的问题
                auto value = visit(info.initial).as<Value*>();
                builder.CreateStore(value,ptr);
            }
        }
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTypeDecl(BasicParser::TypeDeclContext *ctx) override {
        vector<Type*> paramList;
        vector<ArgumentInfo> arguments;
        for(auto arg:ctx->variable()){
            arguments.push_back(visit(arg).as<ArgumentInfo>());
            paramList.push_back(arguments.back().type);
        }
        return StructType::create(paramList,strToLower(ctx->name->getText()));
    }

    virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *ctx) override {
        ArgumentInfo info(ctx,typeTable);
        return info;
    }

//    virtual antlrcpp::Any visitLine(BasicParser::LineContext *ctx) override {
//        return visit(ctx->statement());
//    }


    virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *ctx) override {

        vector<Type*> paramList;
        vector<ArgumentInfo> arguments;
        for(auto arg:ctx->variable()){
            arguments.push_back(visitVariable(arg).as<ArgumentInfo>());
            paramList.push_back(arguments.back().type);
        }
        Type* retType = typeTable.find(ctx->returnType);
        FunctionType *type = FunctionType::get(retType,paramList,false);
        auto function = Function::Create(type,Function::ExternalLinkage,strToLower(ctx->name->getText()),mod);
        frame.push(StackFrame(function));
        auto block = BasicBlock::Create(context, "EntryBlock", function);
        builder.SetInsertPoint(block);
        auto param = function->arg_begin();
        for(auto& arg:arguments){
            param->setName(arg.name);
            param++;
        }
        visitBlock(ctx->block);
        frame.pop();
        return function;
    }

    virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *ctx) override {
        vector<Type*> paramList;
        vector<ArgumentInfo> arguments;
        for(auto& arg:ctx->variable()){
            arguments.push_back(visit(arg).as<ArgumentInfo>());
            paramList.push_back(arguments.back().type);
        }
        FunctionType *type = FunctionType::get(Type::getVoidTy(context),paramList,false);
        string funcionName = ctx->name->getText();
        auto function = Function::Create(type,Function::ExternalLinkage,strToLower(ctx->name->getText()),mod);
        frame.push(StackFrame(function));
        auto block = BasicBlock::Create(context, "EntryBlock", function);
        builder.SetInsertPoint(block);
        auto param = function->arg_begin();
        for(auto& arg:arguments){
            param->setName(arg.name);
            param++;
        }
        visitBlock(ctx->block);
        frame.pop();
        return function;
    }
    //====================================== call statement =========================================
    virtual antlrcpp::Any visitInnerCall(BasicParser::InnerCallContext *ctx) override {
        for(auto p:ctx->passArg())cout<<p<<endl;
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitArgPassValue(BasicParser::ArgPassValueContext *ctx) override {
        return visitChildren(ctx);

    }
    virtual antlrcpp::Any visitArgIgnore(BasicParser::ArgIgnoreContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitArgOptional(BasicParser::ArgOptionalContext *ctx) override {
        return visitChildren(ctx);
    }


    virtual antlrcpp::Any visitReturnStmt(BasicParser::ReturnStmtContext *ctx) override {
        auto val = visit(ctx->exp()).as<Value*>();
        builder.CreateRet(val);
        return nullptr;
    }

    virtual antlrcpp::Any visitAssignStmt(BasicParser::AssignStmtContext *ctx) override {
        auto val = visit(ctx->right).as<Value*>();
        auto ptr = frame.top().varTable.find(strToLower(ctx->left->getText()))->second;
        builder.CreateStore(val,ptr);
        return (Value*)ptr;
    }

    virtual antlrcpp::Any visitPluOp(BasicParser::PluOpContext *ctx) override {
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = ctx->op->getText();
        if(op=="+")
            return builder.CreateAdd(l,r);
        else 
            return builder.CreateSub(l,r);
    }

    map<string,CmpInst::Predicate> cmpIntSigned={
        {"=",CmpInst::Predicate::ICMP_EQ},
        {"<>",CmpInst::Predicate::ICMP_NE},
        {"<",CmpInst::Predicate::ICMP_SLT},
        {"<=",CmpInst::Predicate::ICMP_SLE},
        {"=<",CmpInst::Predicate::ICMP_SLE},
        {">",CmpInst::Predicate::ICMP_SGT},
        {">=",CmpInst::Predicate::ICMP_SGE},
        {"=>",CmpInst::Predicate::ICMP_SGE}
    };

    virtual antlrcpp::Any visitCmpOp(BasicParser::CmpOpContext *ctx) override {
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = ctx->op->getText();
        return builder.CreateCmp(cmpIntSigned[op],l,r);
        //TODO:支持不同类型
    }   

    virtual antlrcpp::Any visitLogicNotOp(BasicParser::LogicNotOpContext *ctx) override {
        auto r = visit(ctx->right).as<llvm::Value*>();
        return builder.CreateNot(r);
    }

    virtual antlrcpp::Any visitNegOp(BasicParser::NegOpContext *ctx) override {
        auto r = visit(ctx->right).as<llvm::Value*>();
        return builder.CreateNeg(r);
    }

    virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override {
        return visitChildren(ctx);//TODO:String
    }

    virtual antlrcpp::Any visitInteger(BasicParser::IntegerContext *ctx) override {
        //TODO:支持浮点数/整数区分
        int n=std::stoi(ctx->Integer()->getSymbol()->getText());
        return (Value*)ConstantInt::get(Type::getInt32Ty(context),n,true);
    }

    virtual antlrcpp::Any visitDecimal(BasicParser::DecimalContext *ctx) override {
        cout<<"double\n";
        double n=std::stod(ctx->Decimal()->getSymbol()->getText());
        return (Value*)ConstantFP::get(Type::getDoubleTy(context),n);
    }

    virtual antlrcpp::Any visitBucket(BasicParser::BucketContext *ctx) override {
        return visit(ctx->exp());
    }

    virtual antlrcpp::Any visitMulOp(BasicParser::MulOpContext *ctx) override {
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = ctx->op->getText();
        if(op=="*")return builder.CreateMul(l,r);
        else if(op=="/"||op=="\\")return builder.CreateSDiv(l,r);//TODO: 支持两种除法
    }

    virtual antlrcpp::Any visitPowModOp(BasicParser::PowModOpContext *ctx) override {
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = strToLower(ctx->op->getText());
        return visitChildren(ctx);//TODO:pow和mod运算
    }

    virtual antlrcpp::Any visitID(BasicParser::IDContext *ctx) override {
        auto p = frame.top().varTable.find(strToLower(ctx->ID()->getText()));
        Value* val = builder.CreateLoad(p->second->getType(),p->second);
        return val;//TODO：访问变量
    }

    virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *ctx) override {
        //if(ctx->Boolean->)
        return visitChildren(ctx);//TODO:返回布尔值
    }

    virtual antlrcpp::Any visitBitOp(BasicParser::BitOpContext *ctx) override {
    return visitChildren(ctx);//TODO:位运算
    }

    virtual antlrcpp::Any visitLogicOp(BasicParser::LogicOpContext *ctx) override {
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = strToLower(ctx->op->getText());
        if(op=="and")return builder.CreateAnd(l,r);
        else if(op=="or")return builder.CreateOr(l,r);
        else if(op=="xor")return builder.CreateXor(l,r);
    }

};

#endif