
#include <iostream>
#include <string>
#include "Command.h"


using namespace std;


Command :: Command(){
    in="";
    outputc= '$';
    
}


Command :: ~Command(){
    
}










void Command:: print (){ 
     cout << outputc << " ";
}
void Command:: input (){
   getline(cin,in);
   
}
