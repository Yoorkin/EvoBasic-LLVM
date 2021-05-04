//
// Created by yorkin on 4/16/21.
//

#include"codeGen.h"

namespace classicBasic{
    //===================================== visitor =========================================================================
    antlrcpp::Any CodeGenVisitor::visitExitStmt(BasicParser::ExitStmtContext *ctx){
        return nullptr;
    }

    CodeGenVisitor::CodeGenVisitor(GenerateUnit& unit,structure::Scope* scope)
    :reporter(unit.reporter),frame(unit.frame),
    context(unit.context),mod(unit.mod),builder(unit.context),unit(unit),scope(scope){
    }

    antlrcpp::Any CodeGenVisitor::visitForStmt(BasicParser::ForStmtContext *ctx){
        //TODO
//        frame.back().BeginLayer("For");
//        Value* iter;
//        Type* type;
//        string name = strToLower(ctx->iterator->getText());
//        if(ctx->Dim()==nullptr){
//            iter= unit.findVariable(ctx->iterator);
//            type=((AllocaInst*)iter)->getAllocatedType();
//        }
//        else{
//            type = visit(ctx->type).as<Type*>();//TODO: 支持数组与结构体
//            iter = builder.CreateAlloca(type,nullptr,name);
//            unit.addVariableInStack(ctx->iterator, (AllocaInst *) iter);
//        }
//
//        auto begin=visit(ctx->begin).as<Value*>(),span=visit(ctx->end).as<Value*>();
//        auto end=builder.CreateAdd(begin,span);
//        Value* step;
//        if(ctx->Step() == nullptr) step=ConstantInt::get(Type::getInt32Ty(context),1);
//        else step=visit(ctx->step).as<Value*>();
//        builder.CreateStore(begin,iter);
//
//
//        auto condition = BasicBlock::Create(context,frame.back().getBlockName("condition"),frame.back().function);
//        auto loop = BasicBlock::Create(context,frame.back().getBlockName("Loop"),frame.back().function);
//        auto after = BasicBlock::Create(context,frame.back().getBlockName("After"),frame.back().function);
//        builder.CreateBr(loop);
//
//        builder.SetInsertPoint(condition);
//        auto val = builder.CreateLoad(type,iter);
//        auto added = builder.CreateAdd(val,step);
//        builder.CreateStore(added,iter);
//        auto cond = builder.CreateCmp(CmpInst::Predicate::ICMP_SLE,added,end);
//        builder.CreateCondBr(cond,loop,after);
//
//        builder.SetInsertPoint(loop);
//        visitBlock(ctx->block);
//        builder.CreateBr(condition);
//
//        builder.SetInsertPoint(after);
//
//        if(ctx->nextFlag!=nullptr){
//            string flag=strToLower(ctx->nextFlag->getText());
//            if(name!=flag)
//                reporter.report(ctx->nextFlag,"Unexpected next flag '"+flag+"',require '"+name+"'");
//        }
//        frame.back().EndLayer();
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitDoWhile(BasicParser::DoWhileContext *ctx){
        frame.back().BeginLayer("Loop");
        auto condBlock = BasicBlock::Create(context,frame.back().getBlockName("LoopCondition"),frame.back().function);
        auto loop = BasicBlock::Create(context,frame.back().getBlockName("Loop"),frame.back().function);
        auto loopEnd = BasicBlock::Create(context,frame.back().getBlockName("LoopEnd"),frame.back().function);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(condBlock);
        auto condition = visit(ctx->exp()).as<Value*>();
        builder.CreateCondBr(condition,loop,loopEnd);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.back().EndLayer();
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitDoUntil(BasicParser::DoUntilContext *ctx){
        frame.back().BeginLayer("Loop");
        auto condBlock = BasicBlock::Create(context,frame.back().getBlockName("LoopCondition"),frame.back().function);
        auto loop = BasicBlock::Create(context,frame.back().getBlockName("Loop"),frame.back().function);
        auto loopEnd = BasicBlock::Create(context,frame.back().getBlockName("LoopEnd"),frame.back().function);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(condBlock);
        auto condition = visit(ctx->exp()).as<Value*>();
        builder.CreateCondBr(condition,loopEnd,loop);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.back().EndLayer();
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitLoopUntil(BasicParser::LoopUntilContext *ctx){
        frame.back().BeginLayer("Loop");
        auto loop = BasicBlock::Create(context,frame.back().getBlockName("Loop"),frame.back().function);
        auto condBlock = BasicBlock::Create(context,frame.back().getBlockName("LoopCondition"),frame.back().function);
        auto loopEnd = BasicBlock::Create(context,frame.back().getBlockName("LoopEnd"),frame.back().function);
        builder.CreateBr(loop);
        builder.SetInsertPoint(condBlock);
        auto condition = visit(ctx->exp()).as<Value*>();
        builder.CreateCondBr(condition,loopEnd,loop);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.back().EndLayer();
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitLoopWhile(BasicParser::LoopWhileContext *ctx){
        frame.back().BeginLayer("Loop");
        auto loop = BasicBlock::Create(context,frame.back().getBlockName("Loop"),frame.back().function);
        auto condBlock = BasicBlock::Create(context,frame.back().getBlockName("LoopCondition"),frame.back().function);
        auto loopEnd = BasicBlock::Create(context,frame.back().getBlockName("LoopEnd"),frame.back().function);
        builder.CreateBr(loop);
        builder.SetInsertPoint(condBlock);
        auto condition = visit(ctx->exp()).as<Value*>();
        builder.CreateCondBr(condition,loop,loopEnd);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.back().EndLayer();
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitWhileWend(BasicParser::WhileWendContext *ctx){
        frame.back().BeginLayer("Loop");
        auto condition = visit(ctx->exp()).as<Value*>();
        auto condBlock = BasicBlock::Create(context,frame.back().getBlockName("LoopCondition"),frame.back().function);
        auto loop = BasicBlock::Create(context,frame.back().getBlockName("Loop"),frame.back().function);
        auto loopEnd = BasicBlock::Create(context,frame.back().getBlockName("LoopEnd"),frame.back().function);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(condBlock);
        builder.CreateCondBr(condition,loop,loopEnd);
        builder.SetInsertPoint(loop);
        visitBlock(ctx->block);
        builder.CreateBr(condBlock);
        builder.SetInsertPoint(loopEnd);
        frame.back().EndLayer();
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitSingleLineIf(BasicParser::SingleLineIfContext *ctx){
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitMutiLineIf(BasicParser::MutiLineIfContext *ctx){
        list<BasicBlock*> trueBlocks;
        for(auto c:ctx->ifBlock())trueBlocks.push_back(visit(c).as<BasicBlock*>());
        for(auto b:ctx->elseBlock)visit(b);
        auto endBlock = BasicBlock::Create(context,frame.back().getBlockName("IF_End"),frame.back().function);
        builder.CreateBr(endBlock);
        for(auto b:trueBlocks){
            builder.SetInsertPoint(b);
            builder.CreateBr(endBlock);
        }
        builder.SetInsertPoint(endBlock);
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitIfBlock(BasicParser::IfBlockContext *ctx){
        frame.back().BeginLayer("If");
        Value* cond = visit(ctx->exp()).as<Value*>();
        auto trueBlock = BasicBlock::Create(context,frame.back().getBlockName("True"),frame.back().function);
        auto falseBlock = BasicBlock::Create(context,frame.back().getBlockName("False"),frame.back().function);
        builder.CreateCondBr(cond,trueBlock,falseBlock);
        builder.SetInsertPoint(trueBlock);
        visitBlock(ctx->block);
        builder.SetInsertPoint(falseBlock);
        frame.back().EndLayer();
        return trueBlock;
    }

//============================================ declare ====================================================


    antlrcpp::Any CodeGenVisitor::visitVarDecl(BasicParser::VarDeclContext *ctx){
//        for(auto arg:ctx->variable()){
//            auto info = visit(arg).as<VariableInfo>();
//            auto ptr = builder.CreateAlloca(info.type,nullptr,info.name);
//            unit.addVariableInStack(info.token, ptr);
//            if(info.initial!=nullptr){
//                auto value = visit(info.initial).as<Value*>();
//                builder.CreateStore(value,ptr);
//            }
//        }
//        return visitChildren(ctx);
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitTypeDecl(BasicParser::TypeDeclContext *ctx){
//        vector<Type*> paramList;
//        vector<VariableInfo> arguments;
//        for(auto arg:ctx->variable()){
//            arguments.push_back(visit(arg).as<VariableInfo>());
//            paramList.push_back(arguments.back().type);
//        }
//        return StructType::create(paramList,strToLower(ctx->name->getText()));
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitVariable(BasicParser::VariableContext *ctx){
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx){
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitOptionalParameter(BasicParser::OptionalParameterContext *ctx){
        return nullptr;

    }

    antlrcpp::Any CodeGenVisitor::visitFunctionDecl(BasicParser::FunctionDeclContext *ctx){
        string name = strToLower(ctx->name->getText());
        structure::FunctionInfo* info = (structure::FunctionInfo*)scope->memberInfoList.find(name)->second;
        frame.emplace_back(info->function,false);
        BasicBlock* entryBlock = BasicBlock::Create(context,"Entry",info->function);
        builder.SetInsertPoint(entryBlock);
        visitBlock(ctx->block);
        BasicBlock* funcEnd = BasicBlock::Create(context,"FunctionEnd",frame.back().function);
        builder.CreateBr(funcEnd);
        builder.SetInsertPoint(funcEnd);
        //builder.CreateRet(TypeTable::getDefaultValue(info->retInfo->type));
        frame.pop_back();
        return info;
    }

    antlrcpp::Any CodeGenVisitor::visitSubDecl(BasicParser::SubDeclContext *ctx){
//        vector<Type*> paramList;
//        vector<ParameterInfo> arguments;
//        for(auto& arg:ctx->parameter()){
//            arguments.push_back(visit(arg).as<ParameterInfo>());
//            paramList.push_back(arguments.back().type);
//        }
//        FunctionType *type = FunctionType::get(Type::getVoidTy(context),paramList,false);
//        string funcionName = ctx->name->getText();
//        auto function = Function::Create(type,Function::ExternalLinkage,strToLower(ctx->name->getText()),mod);
//        frame.push_back(StackFrame(function,true));
//        auto block = BasicBlock::Create(context, "EntryBlock", function);
//        builder.SetInsertPoint(block);
//        auto param = function->arg_begin();
//        for(auto& info:arguments){
//            param->setName(info.name);
//            if(info.byref){
//                unit.addVariableInStack(info.token,param);
//            }
//            else {
//                auto inst = builder.CreateAlloca(info.type, nullptr);
//                builder.CreateStore(param, inst);
//                unit.addVariableInStack(info.token, inst);
//            }
//            param++;
//        }
//        visitBlock(ctx->block);
//        builder.CreateRetVoid();
//        frame.pop_back();
//        return function;
        return nullptr;
    }
//====================================== call statement =========================================
    antlrcpp::Any CodeGenVisitor::visitInnerCall(BasicParser::InnerCallContext *ctx){
        //TODO
//        Value* value = unit.findVariable(ctx->ID()->getSymbol());
//        if(value == nullptr){
//            Function* func = unit.findFunction(ctx->ID()->getSymbol());
//            if(func == nullptr)
//                reporter.report(ctx->ID()->getSymbol(),"'"+ctx->ID()->getSymbol()->getText()+"' is undefined");
//            vector<Value*> args;
//
//            //TODO 读取参数
//            return (Value*)builder.CreateCall(func,args); //TODO 需要从错误中恢复
//        }
//        else return (Value*)builder.CreateLoad(value-(), value);
        return nullptr;

    }

    antlrcpp::Any CodeGenVisitor::visitArgPassValue(BasicParser::ArgPassValueContext *ctx){
        return visitChildren(ctx);

    }
    antlrcpp::Any CodeGenVisitor::visitArgIgnore(BasicParser::ArgIgnoreContext *ctx){
        return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitArgOptional(BasicParser::ArgOptionalContext *ctx){
        return visitChildren(ctx);
    }


    antlrcpp::Any CodeGenVisitor::visitReturnStmt(BasicParser::ReturnStmtContext *ctx){
        auto val = visit(ctx->exp()).as<Value*>();
        builder.CreateRet(val);
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitAssignStmt(BasicParser::AssignStmtContext *ctx){
        auto val = visit(ctx->right).as<Value*>();
        auto inst = unit.findVariable(ctx->left);
        builder.CreateStore(val,inst);
        return (Value*)inst;
    }

    antlrcpp::Any CodeGenVisitor::visitPluOp(BasicParser::PluOpContext *ctx){
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = ctx->op->getText();
        if(op=="+")
            return builder.CreateAdd(l,r);
        else
            return builder.CreateSub(l,r);
    }

    antlrcpp::Any CodeGenVisitor::visitCmpOp(BasicParser::CmpOpContext *ctx){
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = ctx->op->getText();
        return builder.CreateCmp(cmpIntSigned[op],l,r);
        //TODO:支持不同类型
    }

    antlrcpp::Any CodeGenVisitor::visitLogicNotOp(BasicParser::LogicNotOpContext *ctx){
        auto r = visit(ctx->right).as<llvm::Value*>();
        return builder.CreateNot(r);
    }

    antlrcpp::Any CodeGenVisitor::visitNegOp(BasicParser::NegOpContext *ctx){
        auto r = visit(ctx->right).as<llvm::Value*>();
        return builder.CreateNeg(r);
    }

    antlrcpp::Any CodeGenVisitor::visitString(BasicParser::StringContext *ctx){
        return visitChildren(ctx);//TODO:String
    }

    antlrcpp::Any CodeGenVisitor::visitInteger(BasicParser::IntegerContext *ctx){
        //TODO:支持浮点数/整数区分
        int n=std::stoi(ctx->Integer()->getSymbol()->getText());
        return (Value*)ConstantInt::get(Type::getInt32Ty(context),n,true);
    }

    antlrcpp::Any CodeGenVisitor::visitDecimal(BasicParser::DecimalContext *ctx){
        cout<<"double\n";
        double n=std::stod(ctx->Decimal()->getSymbol()->getText());
        return (Value*)ConstantFP::get(Type::getDoubleTy(context),n);
    }

    antlrcpp::Any CodeGenVisitor::visitBucket(BasicParser::BucketContext *ctx){
        return visit(ctx->exp());
    }

    antlrcpp::Any CodeGenVisitor::visitMulOp(BasicParser::MulOpContext *ctx){
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = ctx->op->getText();
        if(op=="*")return builder.CreateMul(l,r);
        else if(op=="/"||op=="\\")return builder.CreateSDiv(l,r);//TODO: 支持两种除法
    }

    antlrcpp::Any CodeGenVisitor::visitPowModOp(BasicParser::PowModOpContext *ctx){
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = strToLower(ctx->op->getText());
        return visitChildren(ctx);//TODO:pow和mod运算
    }

    antlrcpp::Any CodeGenVisitor::visitID(BasicParser::IDContext *ctx){
        //TODO 检查这个函数还有没有用
        //auto p = frame.back().varTable.find(strToLower(ctx->ID()->getText()));
        //Value* val = builder.CreateLoad(p->second->getType(),p->second);
        //return val;//TODO：访问变量
        return nullptr;
    }

    antlrcpp::Any CodeGenVisitor::visitBoolean(BasicParser::BooleanContext *ctx){
        char val = toLower(ctx->Boolean()->getText()[0]);
        if(val=='t')return (Value*)ConstantInt::getTrue(context);
        else return (Value*)ConstantInt::getFalse(context);
    }

    antlrcpp::Any CodeGenVisitor::visitBitOp(BasicParser::BitOpContext *ctx){
        return visitChildren(ctx);//TODO:位运算
    }

    antlrcpp::Any CodeGenVisitor::visitLogicOp(BasicParser::LogicOpContext *ctx){
        auto l = visit(ctx->left).as<llvm::Value*>();
        auto r = visit(ctx->right).as<llvm::Value*>();
        auto op = strToLower(ctx->op->getText());
        if(op=="and")return builder.CreateAnd(l,r);
        else if(op=="or")return builder.CreateOr(l,r);
        else if(op=="xor")return builder.CreateXor(l,r);
    }
}
