//
// Created by yorkin on 4/27/21.
//
#include"structureGen.h"
#include"ExpGen.h"
namespace classicBasic {
    using namespace structure;

    StructureScan::StructureScan(Unit* unit): unit(*unit), gen(*(unit->gen)){}

    antlrcpp::Any StructureScan::visitAliasDecl(BasicParser::AliasDeclContext *ctx){

    }
    antlrcpp::Any StructureScan::visitModuleDecl(BasicParser::ModuleDeclContext *ctx){
        ModuleInfo* cbModule=new ModuleInfo(ctx->name->getText(), unit.scope);
        unit.scope=cbModule;
        for(auto m:ctx->moduleMember())visit(m);
        unit.scope=cbModule->getParent();
        return nullptr;
    }

    antlrcpp::Any StructureScan::visitClassDecl(BasicParser::ClassDeclContext *ctx){
        ClassInfo* cbClass=new ClassInfo(ctx->name->getText(), unit.scope);
        unit.scope=cbClass;
        for(auto m:ctx->classMember())visit(m);
        unit.scope=cbClass->getParent();
        return nullptr;
    }

    antlrcpp::Any StructureScan::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        info->retInfo=new structure::ParameterInfo(ctx->returnType);
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }
    antlrcpp::Any StructureScan::visitSubDecl(BasicParser::SubDeclContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }

    antlrcpp::Any StructureScan::visitExternalFunction(BasicParser::ExternalFunctionContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        info->retInfo=new structure::ParameterInfo(ctx->returnType);
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }
    antlrcpp::Any StructureScan::visitExternalSub(BasicParser::ExternalSubContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }

    antlrcpp::Any StructureScan::visitPropertyGet(BasicParser::PropertyGetContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText())+"_get";
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        info->retInfo=new structure::ParameterInfo(ctx->returnType);
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }
    antlrcpp::Any StructureScan::visitPropertySet(BasicParser::PropertySetContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText())+"_set";
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }
    antlrcpp::Any StructureScan::visitPropertyLet(BasicParser::PropertyLetContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText())+"_let";
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }

    antlrcpp::Any StructureScan::visitEnumDecl(BasicParser::EnumDeclContext *ctx){
        auto info = new structure::EnumInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        cout<<info->name<<endl;
        cout<<unit.scope->memberInfoList.size()<<endl;
        for(auto p:unit.scope->memberInfoList){
            cout<<p.first<<endl;
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }
    antlrcpp::Any StructureScan::visitTypeDecl(BasicParser::TypeDeclContext *ctx){
        auto info = new structure::TypeInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        for(auto p:ctx->nameTypePair()){
            auto namePair = visit(p).as<pair<string,bool>>();
            ParameterInfo* m=new ParameterInfo(p);
            m->array=namePair.second;
            m->name=namePair.first;
            info->memberInfoList.insert(make_pair(m->name,m));
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        info->parent=unit.scope;
        return info;
    }

    antlrcpp::Any StructureScan::visitParameterList(BasicParser::ParameterListContext *ctx){
        list<structure::ParameterInfo*> args;
        for(auto child:ctx->necessaryParameter()){
            args.push_back(visit(child).as<ParameterInfo*>());
        }
        for(auto child:ctx->optionalParameter()){
            args.push_back(visit(child).as<ParameterInfo*>());
        }
        if(ctx->paramArrayParameter()!=nullptr) {
            args.push_back(visit(ctx->paramArrayParameter()).as<ParameterInfo*>());
        }
        return args;
    }

    antlrcpp::Any StructureScan::visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx){
        auto info = new structure::ParameterInfo((BasicParser::NecessaryParameterContext*)ctx);
        pair<string,bool> p = visit(ctx->nameTypePair()).as<pair<string,bool>>();
        info->name=p.first;
        info->array=p.second;
        return info;
    }

    antlrcpp::Any StructureScan::visitOptionalParameter(BasicParser::OptionalParameterContext *ctx){
        auto info = new structure::ParameterInfo((BasicParser::OptionalParameterContext*)ctx);
        pair<string,bool> p = visit(ctx->nameTypePair()).as<pair<string,bool>>();
        info->name=p.first;
        info->array=p.second;
        info->initial=ctx->initial;
        return info;
    }

    antlrcpp::Any StructureScan::visitParamArrayParameter(BasicParser::ParamArrayParameterContext *ctx){
        auto info = new structure::ParameterInfo((BasicParser::ParamArrayParameterContext*)ctx);
        pair<string,bool> p = visit(ctx->nameTypePair()).as<pair<string,bool>>();
        info->name=p.first;
        info->array=p.second;
        info->paramArray=true;
        return info;
    }

    antlrcpp::Any StructureScan::visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx){
        pair<string,bool> p;
        p.first=strToLower(ctx->name->getText());
        p.second=false;
        return p;
    }
    antlrcpp::Any StructureScan::visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx){
        pair<string,bool> p;
        p.first=strToLower(ctx->name->getText());
        p.second=true;
        return p;
    }



    StructureGen::StructureGen(Unit* unit): unit(*unit), gen(*(unit->gen)){
        this->constExpVisitor=new constExpCompute::ConstExpVisitor(*unit);
    }
    StructureGen::~StructureGen(){
        delete constExpVisitor;
    }
    antlrcpp::Any StructureGen::visitModuleDecl(BasicParser::ModuleDeclContext *ctx){
        ModuleInfo* cbModule=unit.scope->lookUp(ctx->name->getText())->as<ModuleInfo>();
        unit.scope=cbModule;
        for(auto m:ctx->moduleMember())visit(m);
        unit.scope=cbModule->getParent();
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitClassDecl(BasicParser::ClassDeclContext *ctx){
        ClassInfo* cbClass=unit.scope->lookUp(ctx->name->getText())->as<ClassInfo>();
        unit.scope=cbClass;
        for(auto m:ctx->classMember())visit(m);
        unit.scope=cbClass->getParent();
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText()))->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }
        auto retT = info->retInfo->getType(this);

        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        return info;
    }
    antlrcpp::Any StructureGen::visitSubDecl(BasicParser::SubDeclContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText()))->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }

        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.getContext()),typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        return info;
    }

    antlrcpp::Any StructureGen::visitExternalFunction(BasicParser::ExternalFunctionContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText()))->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }
        auto retT = info->retInfo->getType(this);

        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }

        string libPath = ctx->libPath==nullptr ? "" : strToLower(ctx->libPath->getText());
        gen.linkTargetPaths.push_back(libPath.substr(0,libPath.length()-2));
        return info;
    }
    antlrcpp::Any StructureGen::visitExternalSub(BasicParser::ExternalSubContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText()))->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }

        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.getContext()),typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }

        string libPath = ctx->libPath==nullptr ? "" : strToLower(ctx->libPath->getText());
        gen.linkTargetPaths.push_back(libPath.substr(0,libPath.length()-2));
        return info;
    }

    antlrcpp::Any StructureGen::visitPropertyGet(BasicParser::PropertyGetContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText())+"_get")->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }
        info->retInfo=new structure::ParameterInfo(ctx->returnType);
        auto retT = info->retInfo->getType(this);

        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        return info;
    }
    antlrcpp::Any StructureGen::visitPropertySet(BasicParser::PropertySetContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText())+"_set")->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }

        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.getContext()),typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        return info;
    }
    antlrcpp::Any StructureGen::visitPropertyLet(BasicParser::PropertyLetContext *ctx){
        FunctionInfo* info=(FunctionInfo*)Info::handling;
        if(info==nullptr)info = (structure::FunctionInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText())+"_let")->second;

        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->getType(this));
        }

        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.getContext()),typelist,hasParamArray);
        info->setType(fT);
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->mangling(),gen.getModule());
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        return info;
    }

    antlrcpp::Any StructureGen::visitEnumDecl(BasicParser::EnumDeclContext *ctx){
        EnumInfo* info = (EnumInfo*)Info::handling;
        if(info==nullptr)info = (EnumInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText()))->second;
        info->setType(Type::getInt32Ty(gen.getContext()));
        int index=0;
        for(auto pctx:ctx->enumPair()){
            string name = strToLower(pctx->name->getText());
            if(pctx->value!=nullptr){
                auto ret = constExpVisitor->visitConstExp(pctx->value).as<constExpCompute::ExpRetValue>();
                constExpCompute::builtInCast::i32_(ret);
                index=ret.data.i32val;
            }
            info->memberList.insert(make_pair(name,ConstantInt::get(Type::getInt32Ty(gen.getContext()),index)));
            index++;
        }
        return info;
    }

    antlrcpp::Any StructureGen::visitTypeDecl(BasicParser::TypeDeclContext *ctx){
        auto info = (TypeInfo*)Info::handling;
        if(info==nullptr)info=(TypeInfo*)unit.scope->memberInfoList.find(strToLower(ctx->name->getText()))->second;
        vector<Type*> members;
        for(auto m:info->memberInfoList){
            members.push_back(m.second->getType(this));
        }
        info->setType(llvm::StructType::create(members,info->mangling()));
        return info;
    }


    antlrcpp::Any StructureGen::visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx){
        auto info = (TypeInfo*)Info::handling;
        visit(ctx->typeLocation());
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx){
        auto info = (ParameterInfo*)Info::handling;
        visit(ctx->typeLocation());
        info->setType(info->getType(this)->getPointerTo());
        info->array=true;
        if(ctx->size!=nullptr){
            auto expVal = visit(ctx->size).as<constExpCompute::ExpRetValue>();
            constExpCompute::builtInCast::i32_(expVal);
            info->arraySize=expVal.data.i32val;
        }
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitConstExp(BasicParser::ConstExpContext *ctx){
        return constExpVisitor->visit(ctx).as<constExpCompute::ExpRetValue>();
    }

    antlrcpp::Any StructureGen::visitVarDecl(BasicParser::VarDeclContext *ctx){
        return nullptr;//skip variable declare
    }

    antlrcpp::Any StructureGen::visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx){
        auto info = (ParameterInfo*)Info::handling;
        visit(ctx->nameTypePair());
        info->setType(info->getType(this)->getPointerTo());
        info->byval = !(ctx->passFlag==nullptr||strToLower(ctx->passFlag->getText())=="byref");
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitOptionalParameter(BasicParser::OptionalParameterContext *ctx){
        auto info = (ParameterInfo*)Info::handling;
        visit(ctx->nameTypePair());
        info->setType(info->getType(this)->getPointerTo());
        info->initial=ctx->initial;
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitParamArrayParameter(BasicParser::ParamArrayParameterContext *ctx){
        auto info = (ParameterInfo*)Info::handling;
        visit(ctx->nameTypePair());
        info->setType(info->getType(this)->getPointerTo());
        info->paramArray=true;
        return nullptr;
    }

    antlrcpp::Any StructureGen::visitTypeLocation(BasicParser::TypeLocationContext *ctx){
        auto i = (TypeInfo*)Info::handling;
        vector<string> path;
        for(auto p:ctx->path){
            cout<<p->getText()<<endl;
            path.push_back(strToLower(p->getText()));
        }
        path.push_back(strToLower(ctx->target->getText()));
        cout<<ctx->target->getText()<<endl;
        structure::Info* info = unit.scope->lookUp(path);
        i->setType(info->getType(this));
        return info;
    }

    antlrcpp::Any StructureGen::visitInteger(BasicParser::IntegerContext *ctx){
        long number = std::stol(ctx->Integer()->getSymbol()->getText());
        return ConstantInt::get(Type::getInt64Ty(gen.getContext()),number);
    }
}
