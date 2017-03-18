

#include <iostream>
//#include <string>
//#include <vector>
#include "Commandinfo.h"
//#include "Command.h"
#include "Executer.h"
using namespace std;



Commandinfo::Commandinfo() {
} 

Commandinfo::~Commandinfo() {

}


int Commandinfo:: parexist(){
    
    if (in.at(0)=='('){ // erase if the command begisn with a (
          in.erase(in.begin());
                 
    }
    // Delete all right parens
       for(unsigned int i = 0; i < in.size(); i++){
      if(in.at(i) == ')'){
                      in.erase(in.begin()+i);
                 }
      }
    // test that parens exits where zolo means zero opepen parens
      for(unsigned int i = 0; i < in.size(); i++){
           if (in.at(i)=='#'){
           //    for(unsigned int t = i; t < in.size(); t++){
              in.erase(in.begin()+i, in.end());}
              
              
      }
        //  }
         for(unsigned int i = 0; i < in.size(); i++){
          if (in.at(i)=='('){
              zolo=10;
              return 1;
          }
      }
     if (zolo!=10) {
         return 0;
     }
}

void Commandinfo:: Parparser(int suc){
     inner=in;
        
      for(unsigned int i = 0; i < in.size(); i++){ // check for open parens
          if (in.at(i)=='('){
              zolo=10;
          }
           if (inner.at(i)=='#'){ // check for comments
              inner.erase(i,inner.size()-1);
          }
      }
    if (zolo !=10){ // If there are no parns then return
        rawin=in;
        return;
    }
    if (zolo==10){
       if (inner.size()>0){  // if there are elements to look at then continue
           

           for(unsigned int i = 0; i < inner.size(); i++){ // iterate through all elemts until there is a open paren
             if (inner.at(i) == '|' && inner.at(i+1) == '|' && inner.at(i+3) == '('){// if and is found
                if(inner.at(i) != ')') {
 
                    for(unsigned int j = 0; j<i ; j++){ // add everything before parns
                    parsedin.push_back(inner.at(j));
                    }
                 
                 if (suc==1 && ando==1){ // check if the last command succeded and what that command was

                    rawin=parsedin;
                }
                    else if (suc==0 && oro==1){ // check if the last command succeded and what that command was

                    rawin=parsedin;
                    }
                    else if (semio==1){ // check what that command was
   
                    rawin=parsedin;
                    }
                    inner.erase(0,i+4);
                }
              ando=0;
               oro=1;
               semio=0;
                   break;
             }
             // execute everything before the and 
             else if (inner.at(i) == '&' && inner.at(i+1) == '&' && inner.at(i+3) == '('){
                
                
                if(inner.at(i) != ')') {
               
                    for(unsigned int j = 0; j<i ; j++){
                    parsedin.push_back(inner.at(j));
                    }
                     
                      if (suc==1 && ando==1){
             
                    rawin=parsedin;
                }
                    else if (suc==0 && oro==1){

                    rawin=parsedin;
                    }
                    else if (semio==1){
   
                    rawin=parsedin;
                    }
                    inner.erase(0,i+4);
                    
                }
               ando=1;
               oro=0;
               semio=0;
                   break;
             }
             // execute the next command since a ; was bore the parens
             else if (inner.at(i) == ';' && inner.at(i+2) == '('){
                     
                 
                 if(inner.at(i) != ')') {
               
                    for(unsigned int j = 0; j<i ; j++){
                    parsedin.push_back(inner.at(j));
                    }
                     
                      if (suc==1 && ando==1){
                    rawin=parsedin;
                }
                    else if (suc==0 && oro==1){
                    rawin=parsedin;
                    }
                       else if (semio==1){
                    rawin=parsedin;
                    }
                
                    inner.erase(0,i+3);
                    
                }
               ando=1;
               oro=0;
               semio=1;
                   break;
                 
             }
            
         // if we reach the end of the string then we are done, but still need to evaluate the last connector before th
        else if (i==inner.size()-1){
                     
                 
                 if(inner.at(i) != ')') {
                   
                    
                    for(unsigned int j = 0; j<i ; j++){
                    parsedin.push_back(inner.at(j));
                    }
                    
                      if (suc==1 && ando==1){
                    rawin=parsedin;
                }
                    else if (suc==0 && oro==1){
                    rawin=parsedin;
                    }
                       else if (semio==1){
                    rawin=parsedin;
                    }
                
                    inner.erase(0,i+3);
                    
                }
               ando=0;
               oro=0;
               semio=0;
                   break;
                 
             }

       }
        }
    if (suc>2){
            rawin=parsedin;
    }

 parsedin.clear();
    in= inner;
    }
}


int Commandinfo:: stringempty (){
    if (inner.size()<=1 && rawin.size()<=1 ){
        
        return 0;
    }
    else{
        return 1;
    }
}

string Commandinfo:: CreateCommand(){
    
    for (unsigned int i=0; i<rawin.size(); i++){
   
        if (rawin.at(i) == '|' && rawin.at(i+1) == '|'){
            for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
        
            connector = "||";
            segs.push_back(segcom);
            cons.push_back(connector);
            if(i>1){
                rawin.erase(0, i+2);
            i=0;}
      
            segcom="";
          //  break;
        
        }
        else if (rawin.at(i) == '&' && rawin.at(i+1) == '&'){
             for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            
            connector = "&&";
            segs.push_back(segcom);
            cons.push_back(connector);
              if(i>1){
          rawin.erase(0, i+2);
            i=0;}
            segcom="";
       // break;
        }
        else if (rawin.at(i) == ';' ){
                   for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            
            connector = ";";
                segs.push_back(segcom);
           cons.push_back(connector);
              if(i>1){
          rawin.erase(0, i+1);
            i=0;}
       
            segcom="";
        }
        else if (rawin.at(i) == '#' ){
            for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            connector="";
                segs.push_back(segcom);
           cons.push_back(connector);
          
       
            segcom="";
            break;
        }
        else if(i==rawin.size()-1 && rawin.at(i) != '&' && rawin.at(i) != '|'&& rawin.at(i) != ';'&& rawin.at(i) != '#'  ) {//commands with no connectors are not saved
           
             for (unsigned int j=0; j<=i; j++){
                segcom.push_back(rawin.at(j));
            }
            connector="";
     //    cout<<segcom<< endl;
                segs.push_back(segcom);
           cons.push_back(connector);
              if(i>1){
          rawin.erase(0, i+2);
            i=0;}
       
            segcom="";
        }
        else if(rawin.at(i) == 'e' && rawin.at(i+1) == 'x'&& rawin.at(i+2) == 'i'&& rawin.at(i+3) == 't'  ) {//commands with no connectors are not saved

             for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            connector="";
           
                segs.push_back(segcom);
           cons.push_back(connector);
             segs.push_back("exit");
             cons.push_back(connector);
       
            segcom="";
            break;
            
        }
       
          else if (rawin.at(i) == '>' && rawin.at(i+1) != '>'){
             
        //       cout << "I worked" <<endl;
             
                    for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
        
            connector = ">";
       //     cout << segcom << endl;
       //     cout << connector << endl;
            segs.push_back(segcom);
            cons.push_back(connector);
            if(i>1){
                rawin.erase(0, i+1);
            i=0;}
      
            segcom="";
            
            
            
            
        }
         else if (rawin.at(i) == '<' && rawin.at(i+1) != '<'){
            for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
        
            connector = "<";
            segs.push_back(segcom);
            cons.push_back(connector);
            if(i>1){
                rawin.erase(0, i+1);
            i=0;

            }
      
            segcom="";
            
            
            
            
        }
         else if (rawin.at(i) == '>' && rawin.at(i+1) == '>'){
            for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
        
            connector = ">>";
            segs.push_back(segcom);
            cons.push_back(connector);
            if(i>1){
                rawin.erase(0, i+2);
            i=0;
            }
      
            segcom="";
            
        }
        
         else if (rawin.at(i) == '|' && rawin.at(i+1) != '|'){
            for (unsigned int j=0; j<i; j++){
                segcom.push_back(rawin.at(j));
            }
            connector = "|";
            segs.push_back(segcom);
            cons.push_back(connector);
            if(i>1){
                rawin.erase(0, i+1);
            i=0;
            }
            segcom="";
            
            
            
        }
        
        
    }

    return rawin;
}

