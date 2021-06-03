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
    void* sys$malloc(int size) {
        void* mem=malloc(size);
        memList.push_back(mem);
        return mem;
    }
    void sys$free(void* ptr){
        free(ptr);
    }
    void console$puts(char c){

    }
    char console$getChar(){

    }
    void sys$initRT(){

    }
    void sys$terminateRT(){
        for(auto mem:memList)
            free(mem);
    }

}

