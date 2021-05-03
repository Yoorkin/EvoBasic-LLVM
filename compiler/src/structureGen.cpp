//
// Created by yorkin on 4/27/21.
//
#include"structureGen.h"
namespace classicBasic {
    StructureVisitor::StructureVisitor(GenerateUnit& unit,structure::Scope* scope)
    :mod(unit.mod),context(unit.context),reporter(unit.reporter),scope(scope){}

    antlrcpp::Any StructureVisitor::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        auto retT = TypeTable::find(ctx->returnType);
        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        info->retInfo=new structure::ParameterInfo();
        info->retInfo->type=retT;
        //info->retInfo->array=ctx->returnType TODO:支持返回数组
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureVisitor::visitSubDecl(BasicParser::SubDeclContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitExternalFunction(BasicParser::ExternalFunctionContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>();
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        auto retT = TypeTable::find(ctx->returnType);
        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        info->retInfo=new structure::ParameterInfo();
        info->retInfo->type=retT;
        //info->retInfo->array=ctx->returnType TODO:支持返回数组
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureVisitor::visitExternalSub(BasicParser::ExternalSubContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitPropertyGet(BasicParser::PropertyGetContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        auto retT = TypeTable::find(ctx->returnType);
        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        info->retInfo=new structure::ParameterInfo();
        info->retInfo->type=retT;
        //info->retInfo->array=ctx->returnType TODO:支持返回数组
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureVisitor::visitPropertySet(BasicParser::PropertySetContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureVisitor::visitPropertyLet(BasicParser::PropertyLetContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitEnumDecl(BasicParser::EnumDeclContext *ctx){
        auto info = new structure::EnumInfo();
        info->name=strToLower(ctx->name->getText());
        int index=0;
        for(auto pctx:ctx->enumPair()){
            string name = strToLower(pctx->name->getText());
            if(pctx->value!=nullptr)index=std::stoi(pctx->value->getText());
            info->memberList.insert(make_pair(name,ConstantInt::get(Type::getInt32Ty(context),index)));
            index++;
        }
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitTypeDecl(BasicParser::TypeDeclContext *ctx){
        auto info = new structure::TypeInfo();
        vector<Type*> members;
        info->name=strToLower(ctx->name->getText());
        for(auto pctx:ctx->nameTypePair()){
            NameTypePairTmp p = visit(pctx).as<NameTypePairTmp>();
            info->memberInfoList.insert(make_pair(p.name,p.type));
            members.push_back(p.type);
        }
        info->structure=llvm::StructType::create(members,info->name);
        scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitVarDecl(BasicParser::VarDeclContext *ctx){
        for(auto v:ctx->variable()) {
            auto info = visit(v).as<structure::VariableInfo *>();
            scope->memberInfoList.insert(make_pair(info->name,info));
        }
        return nullptr;
    }
    antlrcpp::Any StructureVisitor::visitVariable(BasicParser::VariableContext *ctx){
        auto info = new structure::VariableInfo();
        NameTypePairTmp p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
        mod.getOrInsertGlobal(p.name,p.type);
        info->type=p.type;
        info->name=p.name;
        info->variable=mod.getNamedGlobal(p.name);
        info->variable->setLinkage(GlobalValue::CommonLinkage);
        return info;
    }

    antlrcpp::Any StructureVisitor::visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx){
        NameTypePairTmp tmp;
        tmp.isArray=false;
        tmp.name=strToLower(ctx->name->getText());
        tmp.type=TypeTable::find(ctx->typeLocation());
        return tmp;
    }
    antlrcpp::Any StructureVisitor::visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx){
        NameTypePairTmp tmp;
        tmp.isArray=true;
        tmp.type=TypeTable::find(ctx->typeLocation(),true);
        return tmp;
    }

    antlrcpp::Any StructureVisitor::visitParameterList(BasicParser::ParameterListContext *ctx){
        list<structure::ParameterInfo*> args;
        for(auto child:ctx->necessaryParameter()){
            auto arg=visit(child).as<structure::ParameterInfo*>();
            args.push_back(arg);
        }
        for(auto child:ctx->optionalParameter()){
            auto arg=visit(child).as<structure::ParameterInfo*>();
            args.push_back(arg);
        }
        if(ctx->paramArrayParameter()!=nullptr) {
            auto arg = visit(ctx->paramArrayParameter()).as<structure::ParameterInfo *>();
            args.push_back(arg);
        }
        return args;
    }
    antlrcpp::Any StructureVisitor::visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx){
        auto info = new structure::ParameterInfo();
        auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
        info->type=p.type;
        info->name=p.name;
        info->byval = !(ctx->passFlag==nullptr||strToLower(ctx->passFlag->getText())=="byref");
        return info;
    }
    antlrcpp::Any StructureVisitor::visitOptionalParameter(BasicParser::OptionalParameterContext *ctx){
        auto info = new structure::ParameterInfo();
        auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
        info->type=p.type;
        info->name=p.name;
        info->initial=ctx->initial;
        return info;
    }
    antlrcpp::Any StructureVisitor::visitParamArrayParameter(BasicParser::ParamArrayParameterContext *ctx){
        auto info = new structure::ParameterInfo();
        auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
        info->type=p.type;
        info->name=p.name;
        info->paramArray=true;
        return info;
    }

}
