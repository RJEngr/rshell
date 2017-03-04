#ifndef COMMANDINFO_H
#define COMMANDINFO_H
#include <iostream>
#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class Commandinfo : public Command  {
    protected:
    string rawin;
    string connector;
    string segcom;
    string parsedin;
   int mine;
    vector <string> segs;
    vector <string> cons;
    string inner;
    int ando;
    int oro;
    int semio;
    int zolo;
    
    
    
    
    public:
    Commandinfo();
    ~Commandinfo();
    string CreateCommand();
    void Parparser(int suc);
    int stringempty();
    int parexist();
};
#endif