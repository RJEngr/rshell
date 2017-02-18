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
   int mine;
    vector <string> segs;
    vector <string> cons;
    
    public:
    Commandinfo();
    ~Commandinfo();
    string CreateCommand();
};
#endif