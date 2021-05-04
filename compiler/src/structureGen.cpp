//
// Created by yorkin on 4/27/21.
//
#include"structureGen.h"
namespace classicBasic {
    StructureVisitor::StructureVisitor(GenerateUnit& unit):unit(unit),gen(unit.gen){}

    antlrcpp::Any StructureVisitor::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
        auto info = new structure::FunctionInfo();
        info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
        vector<Type*> typelist;
        bool hasParamArray=false;
        for(auto p:info->parameterInfoList){
            if(p->paramArray) hasParamArray=true;
            else typelist.push_back(p->type);
        }
        auto retT = visit(ctx->returnType).as<structure::Info*>()->type;
        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,unit.mod);
        info->retInfo=new structure::ParameterInfo();
        info->retInfo->type=retT;
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        //info->retInfo->array=ctx->returnType TODO:支持返回数组
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
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
        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,unit.mod);
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
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
        auto retT = structure::Scope::global->lookUp(ctx->returnType->getText())->type;
        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,unit.mod);
        info->retInfo=new structure::ParameterInfo();
        info->retInfo->type=retT;
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        string libPath = strToLower(ctx->libPath->getText());
        gen.linkTargetPaths.push_back(libPath.substr(0,libPath.length()-2));
        //info->retInfo->array=ctx->returnType TODO:支持返回数组
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
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
        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,unit.mod);
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
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
        auto retT = structure::Scope::global->lookUp(ctx->returnType->getText())->type;
        FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name+"_get",unit.mod);
        info->retInfo=new structure::ParameterInfo();
        info->retInfo->type=retT;
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        //info->retInfo->array=ctx->returnType TODO:支持返回数组
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
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
        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name+"_set",unit.mod);
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
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
        FunctionType* fT = FunctionType::get(Type::getVoidTy(gen.context),typelist,hasParamArray);
        info->name=strToLower(ctx->name->getText());
        info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name+"_let",unit.mod);
        auto arg_iter=info->function->arg_begin();
        for(auto p:info->parameterInfoList){
            arg_iter->setName(p->name);
            if(p->byval)arg_iter->addAttr(Attribute::AttrKind::ByVal);
            arg_iter++;
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitEnumDecl(BasicParser::EnumDeclContext *ctx){
        auto info = new structure::EnumInfo();
        info->name=strToLower(ctx->name->getText());
        int index=0;
        for(auto pctx:ctx->enumPair()){
            string name = strToLower(pctx->name->getText());
            if(pctx->value!=nullptr)index=std::stoi(pctx->value->getText());
            info->memberList.insert(make_pair(name,ConstantInt::get(Type::getInt32Ty(gen.context),index)));
            index++;
        }
        unit.scope->memberInfoList.insert(make_pair(info->name,info));

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
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureVisitor::visitVarDecl(BasicParser::VarDeclContext *ctx){
        for(auto v:ctx->variable()) {
            auto info = visit(v).as<structure::VariableInfo *>();
            unit.scope->memberInfoList.insert(make_pair(info->name,info));
        }
        return nullptr;
    }
    antlrcpp::Any StructureVisitor::visitVariable(BasicParser::VariableContext *ctx){
        auto info = new structure::VariableInfo();
        NameTypePairTmp p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
        unit.mod.getOrInsertGlobal(p.name,p.type);
        info->type=p.type;
        info->name=p.name;
        info->variable=unit.mod.getNamedGlobal(p.name);
        info->variable->setLinkage(GlobalValue::CommonLinkage);
        return info;
    }

    antlrcpp::Any StructureVisitor::visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx){
        NameTypePairTmp tmp;
        tmp.isArray=false;
        tmp.name=strToLower(ctx->name->getText());
        tmp.type=visit(ctx->typeLocation()).as<structure::Info*>()->type;
        return tmp;
    }
    antlrcpp::Any StructureVisitor::visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx){
        NameTypePairTmp tmp;
        tmp.isArray=true;
        tmp.type=visit(ctx->typeLocation()).as<structure::Info*>()->type;
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
        info->array=p.isArray;
        info->byval = !(ctx->passFlag==nullptr||strToLower(ctx->passFlag->getText())=="byref");
        return info;
    }

    antlrcpp::Any StructureVisitor::visitOptionalParameter(BasicParser::OptionalParameterContext *ctx){
        auto info = new structure::ParameterInfo();
        auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
        info->type=p.type;
        info->name=p.name;
        info->array=p.isArray;
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

    antlrcpp::Any StructureVisitor::visitTypeLocation(BasicParser::TypeLocationContext *ctx){
        vector<string> path;
        for(auto p:ctx->path){
            cout<<p->getText()<<endl;
            path.push_back(strToLower(p->getText()));
        }
        path.push_back(strToLower(ctx->target->getText()));
        cout<<ctx->target->getText()<<endl;
        structure::Info* info = structure::Scope::global->lookUp(path);
        return info;
    }
}
