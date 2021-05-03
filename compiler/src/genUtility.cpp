//
// Created by yorkin on 4/27/21.
//
#include"genUtility.h"

namespace classicBasic{
    string strToLower(string str){
        transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
        return str;
    }

    GenerateUnit::GenerateUnit(CodeGenerator& gen,string path,string name,istream& in,ostream& out)
            :gen(gen),in(in),out(out),context(gen.context),mod(name,gen.context),reporter(out,in,path),errorListener(reporter){
        gen.reporter=&this->reporter;
        ANTLRInputStream input(in);
        BasicLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        BasicParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(&errorListener);
        tree = parser.moduleBody();
        StructureVisitor visitor(*this,gen.globalScope);
//        CodeGenVisitor visitor(*this,gen.globalScope);
        visitor.visit(tree);
    }
    void GenerateUnit::scan(){

    }
    void GenerateUnit::generate(){
        //CodeGenVisitor visitor(*this,&structure::globalScope);
        //visitor.visit(tree);
        //gen.reporter=nullptr;
        //mod.print(outs(),nullptr,false);
    }
    void GenerateUnit::printIR(){
        mod.print(outs(),nullptr,false);
    }

    Function* GenerateUnit::findFunction(Token* id){
        string name = strToLower(id->getText());
        Function* func = mod.getFunction(name);
        return func;
    }

    Value* GenerateUnit::findVariable(Token* id){
        string name = strToLower(id->getText());
        for(auto iter=frame.rbegin();iter!=frame.rend();iter++){
            auto var=iter->varTable.find(name);
            if(var!=iter->varTable.end()){
                return var->second;
            }
        }
        return nullptr;
    }

    void GenerateUnit::addVariableInStack(Token* id, Value* variable){
        string name = strToLower(id->getText());
        auto p = frame.back().varTable.find(name);
        if(p!=frame.back().varTable.end())
            reporter.report(id,"redefinition of '"+name+"'");
        else
            frame.back().varTable.insert(make_pair(name,variable));
    }

    CodeGenerator::CodeGenerator(){
        LLVMInitializeNativeTarget();
        LLVMInitializeNativeAsmPrinter();
        TypeTable::SetGenerator(this);
        globalScope=new structure::Scope();
    }


    CodeGenerator* TypeTable::gen=nullptr;
    map<string,llvm::Type*> TypeTable::builtInTypes;
    map<string,llvm::Type*> TypeTable::builtInTypesPtr;
    map<string,Value*> TypeTable::defaultValue;

    void TypeTable::SetGenerator(CodeGenerator* gen){
        TypeTable::gen=gen;
        builtInTypes.operator=({
                                       {"integer",Type::getInt32Ty(gen->context)},
                                       {"single",Type::getFloatTy(gen->context)},
                                       {"double",Type::getDoubleTy(gen->context)},
                                       {"boolean",Type::getInt1Ty(gen->context)},
                                       {"long",Type::getInt64Ty(gen->context)},
                                       {"byte",Type::getInt8Ty(gen->context)}
                               });
        builtInTypesPtr.operator=({
                                          {"integer",Type::getInt32PtrTy(gen->context)},
                                          {"single",Type::getFloatPtrTy(gen->context)},
                                          {"double",Type::getDoublePtrTy(gen->context)},
                                          {"boolean",Type::getInt1PtrTy(gen->context)},
                                          {"long",Type::getInt64PtrTy(gen->context)},
                                          {"byte",Type::getInt8PtrTy(gen->context)}
                                  });
        defaultValue.operator=({
                                       {"integer",ConstantInt::get(builtInTypes["integer"],0)},
                                       {"single",ConstantFP::get(builtInTypes["single"],0)},
                                       {"double",ConstantFP::get(builtInTypes["double"],0)},
                                       {"boolean",ConstantInt::get(builtInTypes["boolean"],0)},
                                       {"long",ConstantInt::get(builtInTypes["long"],0)},
                                       {"byte",ConstantInt::get(builtInTypes["byte"],0)}
                               });
    }

    Type* TypeTable::find(Token* type,bool ptr){
        map<string,llvm::Type*> &table = ptr?builtInTypesPtr:builtInTypes;
        string name = strToLower(type->getText());
        auto builtIn = table.find(name);
        if(builtIn!=table.end())return builtIn->second;
        if(gen->reporter!=nullptr)
            gen->reporter->report(type,"unexpected type "+type->getText());
        else
            throw "Can not find reporter.\n";
        return Type::getInt32Ty(gen->context);
    }
    Type* TypeTable::find(BasicParser::TypeLocationContext* type,bool ptr){
        return find(type->target);
        //TODO TypeTable::find
    }
    Value* TypeTable::getDefaultValue(Token* type){
        string name = strToLower(type->getText());
        auto ret = defaultValue.find(name);
        if(ret==defaultValue.end()){
            //必不可以是找不到默认值的情况
            gen->reporter->report(type,"默认初始化失败，找不到该类型的默认值");
        }
        return ret->second;
    }

    namespace structure {
        void Scope::extend(Scope* scope){
            childScope.insert(make_pair(scope->name,scope));
            for(auto p:scope->memberInfoList){
                //TODO:添加合并命名空间时命名冲突的错误处理
                memberInfoList.insert(p);
            }
        }
    }
}

