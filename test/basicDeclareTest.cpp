//
// Created by yorkin on 5/15/21.
//
#include<gtest/gtest.h>
#include<JIT/JIT.h>
#include<string>
using namespace classicBasic;
using namespace classicBasic::structure;
using namespace std;

TEST(DeclareTest,TypeMemberTest){
    string code=R"code(
        Type myType
            mlong as long
            minteger as integer
            msingle as single
            mdouble as double
            mboolean as boolean
            mbyte as byte

            aulong[10] as long
            auinteger[10] as integer
            ausingle[10] as single
            audouble[10] as double
            auboolean[10] as boolean
            aubyte[10] as byte
        end type

    )code";
    stringstream stream(code);
    CodeGenerator generator(cout,"test");
    auto unit = generator.createUnitFromStream(stream);
    TypeInfo* info = unit->scope->memberInfoList.find("mytype")->second->as<TypeInfo>();
    auto& list=info->memberInfoList;
    auto cannotFind = list.end();

#define getm(name) auto m##name=list.find("m"#name);\
                    auto a##name=list.find("au"#name);\
                    EXPECT_NE(m##name,cannotFind);\
                    EXPECT_NE(a##name,cannotFind);\
                    EXPECT_EQ(a##name->second->as<ParameterInfo>()->array,true);\
                    EXPECT_EQ(a##name->second->as<ParameterInfo>()->arraySize,10);

    getm(long)
    getm(integer)
    getm(single)
    getm(double)
    getm(boolean)
    getm(byte)

}

TEST(DeclareTest,GlobalVariableTest){
    string code=R"code(
        dim mlong as long
        dim minteger as integer
        dim msingle as single
        dim mdouble as double
        dim mboolean as boolean,mbyte as byte
        dim mmytype as myType
        dim mmyenum as myEnum

        dim aulong[10] as long
        dim auinteger[10] as integer
        dim ausingle[10] as single
        dim audouble[10] as double
        dim auboolean[10] as boolean,aubyte[10] as byte
        dim amytype[10] as myType
        dim amyenum[10] as myEnum

        Type myType
            a as long
            b as integer
        end type

        Enum myEnum
            m1
            m2
        end Enum

    )code";
    stringstream stream(code);
    CodeGenerator generator(cout,"test");
    auto unit = generator.createUnitFromStream(stream);
    auto& list = unit->scope->memberInfoList;

}

TEST(DeclareTest,EnumMemberTest){
    string code=R"code(
        Enum myEnum
            m1
            m2
        end Enum

        Enum myEnum2
            m1=5+10-(1+2)
            m2
        end Enum

    )code";
    stringstream stream(code);
    CodeGenerator generator(cout,"test");
    auto unit = generator.createUnitFromStream(stream);
    unit->generate();
    auto& e1 = unit->scope->memberInfoList.find("myenum")->second->as<EnumInfo>()->memberList;
    auto e1m1 = e1.find("m1");
    auto e1m2 = e1.find("m2");
    EXPECT_NE(e1m1,e1.end());
    EXPECT_NE(e1m2,e1.end());
    EXPECT_EQ(e1m1->second->getZExtValue(),0);
    EXPECT_EQ(e1m2->second->getZExtValue(),1);

    auto& e2 = unit->scope->memberInfoList.find("myenum2")->second->as<EnumInfo>()->memberList;
    auto e2m1 = e2.find("m1");
    auto e2m2 = e2.find("m2");
    EXPECT_NE(e2m1,e2.end());
    EXPECT_NE(e2m2,e2.end());
    EXPECT_EQ(e2m1->second->getZExtValue(),12);
    EXPECT_EQ(e2m2->second->getZExtValue(),13);
}

TEST(DeclareTest,FunctionParameterTest){
    string code=R"code(
        function test(ary[] as long,a as long,byval b as byte,optional c as integer=100,paramArray d as boolean)

        end function
    )code";
    stringstream stream(code);
    CodeGenerator generator(cout,"test");
    auto unit = generator.createUnitFromStream(stream);
    unit->generate();
    auto f = (FunctionInfo*)unit->scope->memberInfoList.find("test")->second;
    auto i=f->parameterInfoList.begin();
    EXPECT_EQ((*i)->name,"ary");
    EXPECT_EQ((*i)->array,true);
    EXPECT_EQ((*i)->byval,false);
    i++;
    EXPECT_EQ((*i)->name,"a");
    EXPECT_EQ((*i)->byval,false);
    EXPECT_EQ((*i)->array,false);
    i++;
    EXPECT_EQ((*i)->name,"b");
    EXPECT_EQ((*i)->byval,true);
    EXPECT_EQ((*i)->array,false);
    i++;
    EXPECT_EQ((*i)->name,"c");
    EXPECT_EQ((*i)->byval,false);
    EXPECT_EQ((*i)->array,false);
    EXPECT_NE((*i)->initial,nullptr);
    i++;
    EXPECT_EQ((*i)->name,"d");
    EXPECT_EQ((*i)->paramArray,true);
    EXPECT_EQ((*i)->byval,false);
    EXPECT_EQ((*i)->array,false);
}