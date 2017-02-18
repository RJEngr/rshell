

#include <iostream>
//#include <string>
//#include <vector>
#include "Commandinfo.h"
//#include "Command.h"

using namespace std;



Commandinfo::Commandinfo() {
  // rawin = in;
//   cout << "test "  << endl;
} 

Commandinfo::~Commandinfo() {

} 

string Commandinfo:: CreateCommand(){
     rawin = in;
//    cout << rawin.size()  << endl;
    
    for (int i=0; i<rawin.size(); i ++){
   
        if (rawin.at(i) == '|' && rawin.at(i+1) == '|'){
            for (int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
        
            connector = "||";
            cout << segcom << endl << connector << endl;
            segs.push_back(segcom);
            cons.push_back(connector);
            if(i>1){
                rawin.erase(0, i+2);
            i=0;}
      
            segcom="";
          //  break;
        
        }
        else if (rawin.at(i) == '&' && rawin.at(i+1) == '&'){
             for (int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            
            connector = "&&";
            cout << segcom << endl << connector << endl;
            segs.push_back(segcom);
            cons.push_back(connector);
              if(i>1){
          rawin.erase(0, i+2);
            i=0;}
            segcom="";
       // break;
        }
        else if (rawin.at(i) == ';' ){
                   for (int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            
            connector = ";";
            cout << segcom << endl << connector << endl;
                segs.push_back(segcom);
           cons.push_back(connector);
              if(i>1){
          rawin.erase(0, i+1);
            i=0;}
       
            segcom="";
        }
        else if (rawin.at(i) == '#' ){
            break;
        }
        else if(i==rawin.size()-1 && rawin.at(i) != '&' && rawin.at(i) != '|'&& rawin.at(i) != ';'&& rawin.at(i) != '#'  ) {//commands with no connectors are not saved
           // cout << rawin.size();
             for (int j=0; j<=i; j++){
                segcom.push_back(rawin.at(j));
            }
            connector="";
             cout << segcom << endl << connector << endl;
                segs.push_back(segcom);
           cons.push_back(connector);
              if(i>1){
          rawin.erase(0, i+2);
            i=0;}
       
            segcom="";
            
            
        }
        
        
        
        
        
        
    }
    /*    cout << "contents of segs: " << segs.size() << endl;
        for(int k = 0; k < segs.size(); k++) {
            cout << k << ": " << segs[k] << endl;
        }*/
    return rawin;
}

