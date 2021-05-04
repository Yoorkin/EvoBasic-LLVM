//
// Created by yorkin on 4/27/21.
//
#include"genUtility.h"

namespace classicBasic{
    string strToLower(string str){
        transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
        return str;
    }

    void strToLowerByRef(string& str){
        transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
    }

    GenerateUnit::GenerateUnit(CodeGenerator& gen,string path,string name,istream& in,ostream& out)
            :gen(gen),in(in),out(out),context(gen.context),mod(name,gen.context),input(in),lexer(&input),tokens(&lexer),parser(&tokens){
        Reporter::singleton=new Reporter(out,in,path);
        parser.removeErrorListeners();
        parser.addErrorListener(&errorListener);
        tree = parser.moduleBody();
    }
    void GenerateUnit::scan(){
        StructureVisitor visitor(*this,structure::Scope::global);
        visitor.visit(tree);
    }
    void GenerateUnit::generate(){
        CodeGenVisitor visitor(*this,structure::Scope::global);
        visitor.visit(tree);
    }
    void GenerateUnit::printIR(){
        mod.print(outs(),nullptr,false,true);
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
        using namespace structure;
        Scope::global->memberInfoList.operator=({
            {"integer",new BuiltInType(Type::getInt32Ty(context))},
            {"single",new BuiltInType(Type::getFloatTy(context))},
            {"double",new BuiltInType(Type::getDoubleTy(context))},
            {"boolean",new BuiltInType(Type::getInt1Ty(context))},
            {"long",new BuiltInType(Type::getInt64Ty(context))},
            {"byte",new BuiltInType(Type::getInt8Ty(context))}
        });
    }

    namespace structure {
        Scope* Scope::global=new Scope();

        void Scope::extend(Scope* scope){
            childScope.insert(make_pair(scope->name,scope));
            for(auto p:scope->memberInfoList){
                //TODO:添加合并命名空间时命名冲突的错误处理
                memberInfoList.insert(p);
            }
        }

        Info* Scope::lookUp(vector<string>& path){
            Scope* p=this;
            for(int i=0;i<path.size();i++){
                if(i<path.size()-1){
                    auto next = p->childScope.find(path[i]);
                    if(next==p->childScope.end())return nullptr;
                    p=next->second;
                }
                else{
                    auto target = p->memberInfoList.find(path[i]);
                    if(target==p->memberInfoList.end())return nullptr;
                    return target->second;
                }
            }
        }

        Info* Scope::lookUp(string name){
            Scope* p=this;
            while(p->parent!=nullptr){
                auto target = memberInfoList.find(strToLower(name));
                if(target!=memberInfoList.end())return target->second;
            }

        }
    }
}

