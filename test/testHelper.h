//
// Created by yorkin on 4/22/21.
//

#ifndef CLASSICBASIC_TESTHELPER_H
#define CLASSICBASIC_TESTHELPER_H

#define Begin int failed=0,succeed=0;
#define TestCase(name) int name()
#define Test(name) if(!name()){failed++; \
                    cout<<"Case "<<#name<<" Failed."<<endl;\
                    }else succeed++
#define Report cout<<failed+succeed<<" Total,"<<failed<<" Failed,"<<succeed<<" Succeed"<<endl;
#define ConfigureModule(name,code)  stringstream stream(code);\
                                    CodeGenerator generator;  \
                                    auto unit=generator.CreateUnit(name,stream,std::cout);\
                                    unit->generate();\
                                    unit->printIR();\
                                    JIT jit;\
                                    jit.addUnit(unit)

#endif //CLASSICBASIC_TESTHELPER_H
