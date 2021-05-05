//
// Created by yorkin on 4/27/21.
//
#include"structureGen.h"
namespace classicBasic {
    StructureScan::StructureScan(GenerateUnit& unit): unit(unit), gen(unit.gen){}

    antlrcpp::Any StructureScan::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureScan::visitSubDecl(BasicParser::SubDeclContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureScan::visitExternalFunction(BasicParser::ExternalFunctionContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureScan::visitExternalSub(BasicParser::ExternalSubContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureScan::visitPropertyGet(BasicParser::PropertyGetContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText())+"_get";
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureScan::visitPropertySet(BasicParser::PropertySetContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText())+"_set";
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
    antlrcpp::Any StructureScan::visitPropertyLet(BasicParser::PropertyLetContext *ctx){
        auto info = new structure::FunctionInfo(ctx);
        info->name=strToLower(ctx->name->getText())+"_let";
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureScan::visitEnumDecl(BasicParser::EnumDeclContext *ctx){
        auto info = new structure::EnumInfo(ctx);
        info->name=strToLower(ctx->name->getText());
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }

    antlrcpp::Any StructureScan::visitTypeDecl(BasicParser::TypeDeclContext *ctx){
        auto info = new structure::TypeInfo(ctx);
        vector<Type*> members;
        info->name=strToLower(ctx->name->getText());
        unit.scope->memberInfoList.insert(make_pair(info->name,info));
        return info;
    }
}
