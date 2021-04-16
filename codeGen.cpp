//
// Created by yorkin on 4/16/21.
//

#include"codeGen.h"


string strToLower(string str){
    transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
    return str;
}

GenerateUnit::GenerateUnit(CodeGenerator& gen,string path,string name,istream& in,ostream& out)
    :gen(gen),in(in),out(out),context(gen.context),mod(name,gen.context),reporter(out,in,path),errorListener(reporter){
    visitor=new Visitor(*this);
}

void GenerateUnit::generate(){
    ANTLRInputStream input(in);
    BasicLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    BasicParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);
    tree::ParseTree *tree = parser.moduleBody();
    visitor->visit(tree);
    mod.print(outs(),nullptr,false);
}

CodeGenerator::CodeGenerator(){
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    typeTable=new TypeTable(*this);
}

TypeTable::TypeTable(CodeGenerator& generator):gen(generator){
        builtInTypes.operator=({
            {"integer",Type::getInt32Ty(gen.context)},
            {"single",Type::getFloatTy(gen.context)},
            {"double",Type::getDoubleTy(gen.context)},
            {"boolean",Type::getInt1Ty(gen.context)},
            {"long",Type::getInt64Ty(gen.context)},
            {"byte",Type::getInt8Ty(gen.context)}
        });
}


Type* TypeTable::find(Token* type){
    string name = strToLower(type->getText());
    auto builtIn = builtInTypes.find(name);
    if(builtIn!=builtInTypes.end())return builtIn->second;
    gen.reporter->report(type->getLine(),type->getCharPositionInLine(),"unexpected type "+type->getText());
    return Type::getInt32Ty(gen.context);
}

//===================================== visitor =========================================================================
Visitor::Visitor(GenerateUnit& unit)
:typeTable(*unit.gen.typeTable),frame(unit.frame),context(unit.context),mod(unit.mod),builder(unit.context),unit(unit){
}
antlrcpp::Any Visitor::visitDoWhile(BasicParser::DoWhileContext *ctx){
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

antlrcpp::Any Visitor::visitDoUntil(BasicParser::DoUntilContext *ctx){
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

antlrcpp::Any Visitor::visitLoopUntil(BasicParser::LoopUntilContext *ctx){
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

antlrcpp::Any Visitor::visitLoopWhile(BasicParser::LoopWhileContext *ctx){
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

antlrcpp::Any Visitor::visitWhileWend(BasicParser::WhileWendContext *ctx){
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

antlrcpp::Any Visitor::visitSingleLineIf(BasicParser::SingleLineIfContext *ctx){
    return nullptr;
}

antlrcpp::Any Visitor::visitMutiLineIf(BasicParser::MutiLineIfContext *ctx){
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

antlrcpp::Any Visitor::visitIfBlock(BasicParser::IfBlockContext *ctx){
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


antlrcpp::Any Visitor::visitVarDecl(BasicParser::VarDeclContext *ctx){
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

antlrcpp::Any Visitor::visitTypeDecl(BasicParser::TypeDeclContext *ctx){
    vector<Type*> paramList;
    vector<ArgumentInfo> arguments;
    for(auto arg:ctx->variable()){
    arguments.push_back(visit(arg).as<ArgumentInfo>());
    paramList.push_back(arguments.back().type);
    }
    return StructType::create(paramList,strToLower(ctx->name->getText()));
}

antlrcpp::Any Visitor::visitVariable(BasicParser::VariableContext *ctx){
    ArgumentInfo info(ctx,typeTable);
    return info;
}

antlrcpp::Any Visitor::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
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

antlrcpp::Any Visitor::visitSubDecl(BasicParser::SubDeclContext *ctx){
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
antlrcpp::Any Visitor::visitInnerCall(BasicParser::InnerCallContext *ctx){
    for(auto p:ctx->passArg())cout<<p<<endl;
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitArgPassValue(BasicParser::ArgPassValueContext *ctx){
    return visitChildren(ctx);

}
antlrcpp::Any Visitor::visitArgIgnore(BasicParser::ArgIgnoreContext *ctx){
    return visitChildren(ctx);
}
antlrcpp::Any Visitor::visitArgOptional(BasicParser::ArgOptionalContext *ctx){
    return visitChildren(ctx);
}


antlrcpp::Any Visitor::visitReturnStmt(BasicParser::ReturnStmtContext *ctx){
    auto val = visit(ctx->exp()).as<Value*>();
    builder.CreateRet(val);
    return nullptr;
}

antlrcpp::Any Visitor::visitAssignStmt(BasicParser::AssignStmtContext *ctx){
    auto val = visit(ctx->right).as<Value*>();
    auto ptr = frame.top().varTable.find(strToLower(ctx->left->getText()))->second;
    builder.CreateStore(val,ptr);
    return (Value*)ptr;
}

antlrcpp::Any Visitor::visitPluOp(BasicParser::PluOpContext *ctx){
    auto l = visit(ctx->left).as<llvm::Value*>();
    auto r = visit(ctx->right).as<llvm::Value*>();
    auto op = ctx->op->getText();
    if(op=="+")
    return builder.CreateAdd(l,r);
    else
    return builder.CreateSub(l,r);
}

//map<string,CmpInst::Predicate> cmpIntSigned={
//        {"=",CmpInst::Predicate::ICMP_EQ},
//        {"<>",CmpInst::Predicate::ICMP_NE},
//        {"<",CmpInst::Predicate::ICMP_SLT},
//        {"<=",CmpInst::Predicate::ICMP_SLE},
//        {"=<",CmpInst::Predicate::ICMP_SLE},
//        {">",CmpInst::Predicate::ICMP_SGT},
//        {">=",CmpInst::Predicate::ICMP_SGE},
//        {"=>",CmpInst::Predicate::ICMP_SGE}
//};

antlrcpp::Any Visitor::visitCmpOp(BasicParser::CmpOpContext *ctx){
    auto l = visit(ctx->left).as<llvm::Value*>();
    auto r = visit(ctx->right).as<llvm::Value*>();
    auto op = ctx->op->getText();
    return builder.CreateCmp(cmpIntSigned[op],l,r);
    //TODO:支持不同类型
}

antlrcpp::Any Visitor::visitLogicNotOp(BasicParser::LogicNotOpContext *ctx){
    auto r = visit(ctx->right).as<llvm::Value*>();
    return builder.CreateNot(r);
}

antlrcpp::Any Visitor::visitNegOp(BasicParser::NegOpContext *ctx){
    auto r = visit(ctx->right).as<llvm::Value*>();
    return builder.CreateNeg(r);
}

antlrcpp::Any Visitor::visitString(BasicParser::StringContext *ctx){
    return visitChildren(ctx);//TODO:String
}

antlrcpp::Any Visitor::visitInteger(BasicParser::IntegerContext *ctx){
    //TODO:支持浮点数/整数区分
    int n=std::stoi(ctx->Integer()->getSymbol()->getText());
    return (Value*)ConstantInt::get(Type::getInt32Ty(context),n,true);
}

antlrcpp::Any Visitor::visitDecimal(BasicParser::DecimalContext *ctx){
    cout<<"double\n";
    double n=std::stod(ctx->Decimal()->getSymbol()->getText());
    return (Value*)ConstantFP::get(Type::getDoubleTy(context),n);
}

antlrcpp::Any Visitor::visitBucket(BasicParser::BucketContext *ctx){
    return visit(ctx->exp());
}

antlrcpp::Any Visitor::visitMulOp(BasicParser::MulOpContext *ctx){
    auto l = visit(ctx->left).as<llvm::Value*>();
    auto r = visit(ctx->right).as<llvm::Value*>();
    auto op = ctx->op->getText();
    if(op=="*")return builder.CreateMul(l,r);
    else if(op=="/"||op=="\\")return builder.CreateSDiv(l,r);//TODO: 支持两种除法
}

antlrcpp::Any Visitor::visitPowModOp(BasicParser::PowModOpContext *ctx){
    auto l = visit(ctx->left).as<llvm::Value*>();
    auto r = visit(ctx->right).as<llvm::Value*>();
    auto op = strToLower(ctx->op->getText());
    return visitChildren(ctx);//TODO:pow和mod运算
}

antlrcpp::Any Visitor::visitID(BasicParser::IDContext *ctx){
    auto p = frame.top().varTable.find(strToLower(ctx->ID()->getText()));
    Value* val = builder.CreateLoad(p->second->getType(),p->second);
    return val;//TODO：访问变量
}

antlrcpp::Any Visitor::visitBoolean(BasicParser::BooleanContext *ctx){
    char val = toLower(ctx->Boolean()->getText()[0]);
    if(val=='t')return (Value*)ConstantInt::getTrue(context);
    else return (Value*)ConstantInt::getFalse(context);
}

antlrcpp::Any Visitor::visitBitOp(BasicParser::BitOpContext *ctx){
    return visitChildren(ctx);//TODO:位运算
}

antlrcpp::Any Visitor::visitLogicOp(BasicParser::LogicOpContext *ctx){
    auto l = visit(ctx->left).as<llvm::Value*>();
    auto r = visit(ctx->right).as<llvm::Value*>();
    auto op = strToLower(ctx->op->getText());
    if(op=="and")return builder.CreateAnd(l,r);
    else if(op=="or")return builder.CreateOr(l,r);
    else if(op=="xor")return builder.CreateXor(l,r);
}