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
    
    int first=1;
    int parex=0;
   
    
  
   
    
  // Commandinfo mycom;
   Executer exec;
   
   while (exec.comyret()!="exit"){
  first=1;
 //   cout << "hello";
   exec.print();
    exec.input();
   parex=exec.parexist();

   exec.Parparser(3);
   
     exec.CreateCommand();
   exec.caller();
    exec.clear();
    
    
    
    
   while ((exec.stringempty()==1 || first==1) && parex==1){
   first=0;
   exec.CreateCommand();
   exec.caller();
    exec.clear();
  //  cout << endl<< exec.stringempty();
    exec.Parparser(exec.miner());
//cout << endl<< exec.stringempty();
    }
    
     
  // cout <<exec.comyret();
}
    return 0;
}