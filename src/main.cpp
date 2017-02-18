#include <iostream>
#include <string>
#include <vector>
#include "Command.h"
#include "Commandinfo.h"
#include "Executer.h"

using namespace std;


int main(){
 
  //  string test = "somelongstring";
    //cout << test;
   // test.erase(0,5);
   // cout << test;
    
   // int t=0;
    
  
   
    
     
  // Commandinfo mycom;
   Executer exec;
   
   while (exec.comyret()!="exit"){
  
 //   cout << "hello";
   exec.print();
    exec.input();
   exec.CreateCommand();
   exec.caller();
    exec.clear();
  // cout <<exec.comyret();
}
    return 0;
}
