//
// Created by yorkin on 4/18/21.
// this is a classicBasic's standard library provide input/output function
//

#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
//inline unsigned short getSize(void* mem,int offset){
//    unsigned short& data=*(unsigned short*)((char*)mem+offset);
//    return data&~(1<<15);
//}
//
//inline bool isUsed(void* mem,int offset){
//    unsigned short& data=*(unsigned short*)((char*)mem+offset);
//    return data&(1<<15);
//}
//
//inline
//
//
//list<pair<void*,int>> memPool;

list<void*> memList;

extern "C" {
    void* _sys_IBN_malloc(int size) {
        void* mem=malloc(size);
        memList.push_back(mem);
        return mem;
    }
    void _sys_IBN_free(void* ptr){
        free(ptr);
    }
    void console_IBN_puts(char c){

    }
    char console_IBN_getChar(){

    }
    void sys_IBN_initRT(){

    }
    void sys_IBN_terminateRT(){
        for(auto mem:memList)
            free(mem);
    }
    char* IBL_getHeader(){
        return R"code(
                Module _sys
                    public Declare Function malloc lib"" (size as integer)as integer
                    public Declare sub free lib""(ptr as integer)
                    public Declare sub initRT lib""()
                    public Declare sub terminateRT lib""()
                End Module

                Module Console
                    public Declare sub puts lib""(c as char)
                    public Declare Function getChar lib""()as char
                End Module
        )code";
    }
}

