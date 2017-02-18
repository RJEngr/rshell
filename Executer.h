#ifndef EXECUTER_H
#define EXECUTER_H
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "Commandinfo.h"




class Executer : public Commandinfo{
    protected:
    pid_t pid;
    char* chargar;
    int pof;
    string comy;
   
       int mine;
       string none;
  
  
    public:
    Executer();
    ~Executer();
    void createproc(string comy);
    void AND(int andpos);
    void OR(int orpos);
    void SEMI(int semipos);
    void caller();
    void  kingbill();
};

#endif