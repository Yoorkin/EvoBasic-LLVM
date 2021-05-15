//
// Created by yorkin on 5/15/21.
//
#include<gtest/gtest.h>
#include<JIT/JIT.h>
#include<string>
using namespace classicBasic;
using namespace classicBasic::structure;
using namespace std;

TEST(StructureTest,GlobalMemberTest){
    string code=R"code(
        sub main(argCount as integer,args() as integer)

        end sub

        function mySub(a as integer)as integer

        end function

        dim a as long, b as integer

        Type MyType
            member1 as boolean
            memeber2 as long
        end Type

        Enum MyEnum
            enumA
            enumB
        end enum
    )code";
    stringstream stream(code);
    CodeGenerator generator;
    auto unit = generator.CreateUnit("main",stream,cout);
    unit->scan();
    auto& list = unit->scope->memberInfoList;
    auto cannotFind = list.end();
    auto mainInfo=list.find("main");
    auto mysubInfo=list.find("mysub");
    auto myenumInfo=list.find("myenum");
    auto mytypeInfo=list.find("mytype");
    auto aInfo=list.find("a");
    auto bInfo=list.find("b");
    EXPECT_NE(mainInfo, cannotFind);
    EXPECT_NE(mysubInfo, cannotFind);
    EXPECT_NE(myenumInfo, cannotFind);
    EXPECT_NE(mytypeInfo, cannotFind);
    EXPECT_NE(aInfo, cannotFind);
    EXPECT_NE(bInfo, cannotFind);
    EXPECT_EQ(mainInfo->second->getKind(),Info::Function);
    EXPECT_EQ(mysubInfo->second->getKind(),Info::Function);
    EXPECT_EQ(mytypeInfo->second->getKind(),Info::Type);
    EXPECT_EQ(myenumInfo->second->getKind(),Info::Enum_);
    EXPECT_EQ(aInfo->second->getKind(),Info::Variable);
    EXPECT_EQ(bInfo->second->getKind(),Info::Variable);
}
