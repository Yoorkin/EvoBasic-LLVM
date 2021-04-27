//
// Created by yorkin on 4/22/21.
//

#ifndef CLASSICBASIC_TESTHELPER_H
#define CLASSICBASIC_TESTHELPER_H
#include<list>
#include<string>
struct TestCaseInfo{
    string testName;
    bool pass;
};
const string RedBegin = "\033[31m";
const string YellowBegin = "\033[33m";
const string ColorEnd = "\033[0m";
#define Begin int failed=0,succeed=0;
#define TestCase(name) int name()
#define Test(name) if(!name()){failed++; \
                    cout<<RedBegin<<"Case "<<#name<<" Failed."<<ColorEnd<<endl;\
                    }else succeed++
#define Report(TestUnitName) cout<<YellowBegin<<TestUnitName<<"  "<<failed+succeed<<" Total,"\
                            <<failed<<" Failed,"<<succeed<<" Succeed"<<ColorEnd<<endl;
#define ConfigureModule(name,code)  stringstream stream(code);\
                                    CodeGenerator generator;  \
                                    auto unit=generator.CreateUnit(name,stream,std::cout);\
                                    unit->generate();\
                                    unit->printIR();\
                                    JIT jit;\
                                    jit.addUnit(unit)



#endif //CLASSICBASIC_TESTHELPER_H
