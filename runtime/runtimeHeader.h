//
// Created by yorkin on 6/3/21.
//

#ifndef CLASSICBASIC_RUNTIMEHEADER_H
#define CLASSICBASIC_RUNTIMEHEADER_H
namespace classicBasic {
    const string RTHeader = R"code(
        Module sys
            public Declare Function malloc(size as integer)as integer
            public Declare sub free(ptr as integer)
            public Declare sub initRT()
            public Declare sub terminateRT()
        End Module

        Module Console
            public Declare sub puts(c as byte)
            public Declare Function getChar()as byte
        End Module
    )code";
}
#endif //CLASSICBASIC_RUNTIMEHEADER_H
