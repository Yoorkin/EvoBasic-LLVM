//
// Created by yorkin on 4/27/21.
//
#include"genUtility.h"
#include"ExpGen.h"

#include <dlfcn.h>

namespace classicBasic{
    string strToLower(string str){
        transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
        return str;
    }

    void strToLowerByRef(string& str){
        transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
    }

    SourceUnit::SourceUnit(CodeGenerator* gen,const string& path,istream& stream):Unit(gen->getContext()){
        this->gen=gen;
        this->scope=gen->getGlobalScope();
        input=new ANTLRInputStream(stream);
        lexer=new BasicLexer(input);
        tokens=new CommonTokenStream(lexer);
        parser=new BasicParser(tokens);
        StructureScan scan(this);
        auto tree = parser->body();
        scan.visit(tree);
        StructureGen genStruct(this);
        genStruct.visit(tree);
    }
    void SourceUnit::generate(){
        CodeGenVisitor visitor(this);
        visitor.visit(parser->body());
    }
    string SourceUnit::getPath(){

    }
    string SourceUnit::operator[](int line){

    }
    SourceUnit::~SourceUnit(){
        delete input;
        delete lexer;
        delete tokens;
        delete parser;
    }

    LibraryUnit::LibraryUnit(CodeGenerator* gen, const string& path):Unit(gen->getContext()){
        if(path=="")return;//IBL内部的Declare lib=“”
        gen->linkTargetPaths.push_back(path);
        typedef char*(*GetHeader)();
        auto h = dlopen(path.c_str(),RTLD_LAZY);
        if(!h)Reporter::singleton->report("库'"+path+"'加载失败");
        else{
            GetHeader getHeader = (GetHeader)dlsym(h,"IBL_getHeader");
            if(getHeader==NULL)Reporter::singleton->report("库'"+path+"'不是有效的INBasic库");
            else{
                string header(getHeader());
                ANTLRInputStream input(header);
                BasicLexer lexer(&input);
                CommonTokenStream tokens(&lexer);
                BasicParser parser(&tokens);
                StructureScan visitor(this);
                visitor.visit(parser.body());
            }
        }
    }
    void LibraryUnit::generate(){

    }
    string LibraryUnit::getPath(){

    }
    string LibraryUnit::operator[](int line){

    }


    void CodeGenerator::printLLVMIR(llvm::raw_ostream& stream){
        mod->print(stream,nullptr,false,true);
    }

    CodeGenerator::CodeGenerator(ostream& output,string name):logger(new Log(output)),log(*logger){
        LLVMInitializeNativeTarget();
        LLVMInitializeNativeAsmPrinter();
        this->context=new llvm::LLVMContext;
        this->mod=new llvm::Module(name,*context);
        using namespace structure;
        this->global=new structure::Scope();
        this->global->memberInfoList.operator=({
            {"integer",new BuiltInType(Type::getInt32Ty(*context))},
            {"single",new BuiltInType(Type::getFloatTy(*context))},
            {"double",new BuiltInType(Type::getDoubleTy(*context))},
            {"boolean",new BuiltInType(Type::getInt1Ty(*context))},
            {"long",new BuiltInType(Type::getInt64Ty(*context))},
            {"byte",new BuiltInType(Type::getInt8Ty(*context))}
        });
        this->global->name="global";
    }

    CodeGenerator::~CodeGenerator(){
        for(auto u:units)delete u;
        delete mod;
        delete context;
        delete logger;
        delete global;
    }

    Unit* CodeGenerator::createUnitFromStream(istream& stream){
        Unit* unit = new SourceUnit(this,"",stream);
        this->units.push_back(unit);
        return unit;
    }
    Unit* CodeGenerator::createUnitFromFile(const string& path){
        ifstream file(path);
        Unit* unit = new SourceUnit(this,path,file);
        this->units.push_back(unit);
        return unit;
    }
    Unit* CodeGenerator:: createUnitFromIBL(string path){
        Unit* unit = new LibraryUnit(this,path);
        this->units.push_back(unit);
        return unit;
    }

    void Log::handling(Unit* u){
        unit=u;
    }
    void Log::handling(Token* t){
        token=t;
    }
    Token* Log::getHandlingToken(){
        return token;
    }
    Unit* Log::getHandlingUnit(){
        return unit;
    }
    const string Log::Red = "\033[31m";
    const string Log::Yellow = "\033[33m";
    const string Log::ColorEnd = "\033[0m";
    const char Log::endl = '\n';

    void Log::stop(){
        out<<errorCount<<" error(s),"<<warningCount<<" warning(s)."<<endl;
    }

    void Log::error(string msg){
        errorCount++;
        (*this)<<Red<<Position<<" error:"<<msg<<ColorEnd<<endl<<TokenMark<<endMsg;
    }

    void Log::warning(string msg){
        warningCount++;
        (*this)<<Position<<" warning:"<<msg<<endl<<TokenMark<<endMsg;
    }

    Log& Log::operator<<(const Enum e){
        if(e==Position){
            out << unit->getPath() << "("
                << token->getLine() << ":" << token->getCharPositionInLine()
                <<")"<<endl;
        }
        else if(e==endMsg){
            out<<"\033[0m\n";
        }
        else if(e==TokenMark){
            out << endMsg << (*unit)[token->getLine()]
                << std::string(token->getCharPositionInLine(),' ')
                << Red << '^' << std::string(token->getStopIndex() - token->getStartIndex() - 1, '~')
                << ColorEnd << endl;
        }
    }

    namespace structure {
        Info* Info::handling=nullptr;

        string Info::mangling(){
            stack<string> path;
            Info* p=this;
            while(p->parent!=nullptr){
                path.push(p->name);
                p=p->parent;
            }
            string ret;
            while(path.size()>1){
                ret+=path.top();
                ret+='.';
                path.pop();
            }
            ret+=path.top();
            return ret;
        }

        llvm::Type* Info::getType(BasicBaseVisitor* visitor){
            if(type==nullptr)load(visitor);
            if(type==nullptr)throw "";
            return type;
        };

        void ParameterInfo::load(BasicBaseVisitor* visitor){
            Info::handling=this;
            if(necessaryParameterCtx!=nullptr)visitor->visit(necessaryParameterCtx);
            else if(paramArrayParameterCtx!=nullptr)visitor->visit(paramArrayParameterCtx);
            else if(optionalParameterCtx!=nullptr)visitor->visit(optionalParameterCtx);
            else if(returnCtx!=nullptr)visitor->visit(returnCtx);
            else if(typeMember!=nullptr)visitor->visit(typeMember);
            Info::handling=nullptr;
        }

        void FunctionInfo::load(BasicBaseVisitor* visitor){
            Info::handling=this;
            if(externalFunctionCtx!=nullptr)visitor->visit(externalFunctionCtx);
            else if(externalSubCtx!=nullptr)visitor->visit(externalSubCtx);
            else if(functionDeclCtx!=nullptr)visitor->visit(functionDeclCtx);
            else if(subDeclCtx!=nullptr)visitor->visit(subDeclCtx);
            else if(propertyGetCtx!=nullptr)visitor->visit(propertyGetCtx);
            else if(propertySetCtx!=nullptr)visitor->visit(propertySetCtx);
            else if(propertyLetCtx!=nullptr)visitor->visit(propertyLetCtx);
            Info::handling=nullptr;
        }

        void TypeInfo::load(BasicBaseVisitor* visitor){
            Info::handling=this;
            visitor->visit(ctx);
            Info::handling=nullptr;
        }

        void EnumInfo::load(BasicBaseVisitor* visitor){
            Info::handling=this;
            visitor->visit(ctx);
            Info::handling=nullptr;
        }

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
                else p=p->getParent();
            }
            Reporter::singleton->report("Undefined Type or Object '" + name +"'");
            return p->memberInfoList.find("integer")->second;
        }

        Info* Scope::lookUp(vector<string>& path){
            if(path.size()==1)return lookUp(path[0]);
            Scope* p=(Scope*)lookUp(path[0]);
            for(int i=1;i<path.size();i++){
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
            throw "error";
        }

    }
}

