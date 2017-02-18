#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Command {
    
    protected:

    char outputc;
    string in;
 
    public:
     Command();
    ~Command();
    void input();
    void print();
};

#endif 
