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

    GenerateUnit::GenerateUnit(CodeGenerator& gen,structure::Scope* parentScope,string path,string name,istream& in,ostream& out)
            :gen(gen),in(in),out(out),mod(name,gen.context),
            input(in),lexer(&input),tokens(&lexer),parser(&tokens){
        scope=new structure::Scope();
        scope->parent=parentScope;
        Reporter::singleton=new Reporter(out,in,path);
        parser.removeErrorListeners();
        parser.addErrorListener(&gen.errorListener);
        tree = parser.moduleBody();
    }

    void GenerateUnit::scan(){
        StructureScan visitor(*this);
        visitor.visit(tree);
        StructureGen v2(*this);
        v2.visit(tree);
    }
    void GenerateUnit::generate(){
//        CodeGenVisitor visitor(*this);
//        visitor.visit(tree);
    }
    void GenerateUnit::printIR(){
        mod.print(outs(),nullptr,false,true);
    }

    Function* GenerateUnit::findFunction(Token* id){
        string name = strToLower(id->getText());
        Function* func = mod.getFunction(name);
        return func;
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

    GenerateUnit* CodeGenerator::CreateUnit(string path,istream& in,ostream& out){
        auto unit=new GenerateUnit(*this,structure::Scope::global,path,path,in,out);
        units.push_back(unit);
        return unit;
    }

    namespace structure {
        Scope* Scope::global=new Scope();
        Info* Info::handling=nullptr;

        void Scope::extend(Scope* scope){
            childScope.insert(make_pair(scope->name,scope));
            for(auto p:scope->memberInfoList){
                //TODO:添加合并命名空间时命名冲突的错误处理
                memberInfoList.insert(p);
            }
        }

        Info* Scope::lookUp(string name){
            Scope* p=this;
            while(p!=nullptr){
                auto target = p->memberInfoList.find(strToLower(name));
                if(target!=p->memberInfoList.end())return target->second;
                else p=p->parent;
            }
            Reporter::singleton->report("Undefined Type or Object '" + name +"'");
            return p->memberInfoList.find("integer")->second;
        }

        Info* Scope::lookUp(vector<string>& path){
            if(path.size()==1)return lookUp(path[0]);
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

    }
}

