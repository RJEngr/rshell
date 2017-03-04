


#include <iostream>
#include <string>
//#include <vector>
#include "Executer.h"
//#include "Command.h"

using namespace std;




Executer::Executer() {
mine =0;


} 

Executer::~Executer() {



} 



void Executer:: caller(){
  //      cout <<segs.at(andpos)<< " Im her 1" ;
    if (segs.size()> 0){
     createproc(segs.at(0));
     comy.clear();}
	
  for (unsigned int i=0; i<cons.size(); i++){
  	
if (segs.at(i)=="exit"){
	comy="exit";
	
	return;
}

    if (cons.at(i)=="&&"){
      AND(i);
    }
     if (cons.at(i)=="||"){
      OR(i);
    }
     if (cons.at(i)==";"){
     	
      SEMI(i);
    }
   /*  if (cons.at(i)==""){
     	if (i==0){
         createproc(segs.at(i));
     	    comy.clear();
     	}
    }*/
  }
}

void Executer:: AND(int andpos){
 // cout << "Trigged";
  	//Always execute left_command

	//Only execute right_command if left_Command is 1
	if(mine == 1){
//	    cout <<segs.at(andpos+1)<< " Im her 2" ;
		 createproc(segs.at(andpos+1));
		 comy.clear();
	}
	else {
		return;
	}
  
  
}

void Executer:: OR(int orpos){
  
  	//Always execute left_command
    // createproc(segs.at(orpos));
   //  comy.clear();
   //  cout << zeus.at(0)<<"within or";
	
	//Only execute right_command if left_Command is 1
	if(mine == 1){

		return;}
	else {
		//cout << zeus.at(0);
		 createproc(segs.at(orpos+1));
		 comy.clear();
		 return;
	}
  
}


void Executer:: SEMI(int semipos){
  
  	//Always execute left_command
  //	if (semipos==0){
  //  createproc(segs.at(semipos));
  //	    comy.clear();
  //	}
	
	//Only execute right_command if left_Command is 1

     createproc(segs.at(semipos+1));
     comy.clear();
     return;
  
  
}




void Executer:: createproc(string comy){



if (comy=="exit"){
	return;
}

 if(comy.at(0) == '[' || comy.compare(0,4,"test") == 0){
	Test (comy);
	return;
}

  
  //comy= segs.at(0);
  // cout<<endl<<"srt is"<< srt<<endl;
  // this line takes the first command for now will change to include others when it works
 
 
  //comy=segs.at(0); // change to i! or call from connectors
  
  //cout << "hello";

  chargar = new char[comy.size() + 1];
  strcpy(chargar, comy.c_str());
  
	char * toke = strtok(chargar, " ");
	char * array[1000];
 
	int i = 0;

	while (toke != 0)	{
		array[i++] = toke;
		toke = strtok(NULL, " ");
	}
	array[i] = NULL;

 
   pid=fork();

   
  
  if (pid < 0) {
        cout<< "Child was aborted"<< endl;
     //   kill(pid, SIGKILL);
     	exit(1);
     //   zeus.at(0) = 0;
        //cout << zeus.at(0) << endl;
     //   return 0;
       }


	if (pid == 0) {

//		cout<< "Child was executed"<< endl;
	    execvp(array[0], array);
	   

		
		
		    cout<< "Failure: Command unknown"<< endl;
		//    kill(pid, SIGKILL);
		    
	
	
		
		
		
		// The demon was found here 
		exit(1);
	
	
}
else { 
  
 //  cout<< "Child was waited"<< endl;
		waitpid(pid, &pof, 0);
		if (pof != 0) {
		  mine=0;
	
		}
		else {
		mine =1;	
		}
	}
//zeus.at(0)=0;

 
//  cout << "CHILD WAS KILLED"<< endl;

			kill(pid, SIGKILL);
		//	exit (1);

/*if (*zeus.at(0) != 1){
   cout << *zeus.at(0) << endl;
  *zeus.at(0) = 0;
	return 0;
	
	
}*/
 //all hail the king #wemadeitfam
  //return 0;
}

string Executer:: comyret(){
	
	return comy;
}

void Executer:: clear(){
	
	segs.clear();
	cons.clear();
	comy.clear();
	
	
}



int Executer:: miner(){
	
	return mine;
}





int Executer::Test(string comy)
{
    struct stat sb;
    string default_flag = "-e ";
    
    
    if((comy.at(0) == '[') && (comy.at(1) == ' ')  && (comy.at(comy.size() - 2) == ' ') && (comy.at(comy.size() - 1) == ']'))
    {
      comy = comy.substr(2, comy.size() - 2);
      if(comy[0] != '-')
      {
        comy = default_flag.append(comy);
      }
      cout << comy;
    }
    
    else if(comy.compare(0,4,"test") == 0)
    {
        comy = comy.substr(5, comy.size() - 1);
        if(comy[0] != '-')
        {
          comy = default_flag.append(comy);
        }
        cout << comy;
    }
    
    else
    {
      cout << "Error with test input, please check syntax" << endl;
       comy.clear();
      return -1;
    }
   
     
    int i = 0;
   
    char* array[100];
    arg = new char[comy.length() + 1];
    strcpy(arg, comy.c_str());
    
    char* tko = strtok(arg, " ");
    
   
    
    while (tko != 0)
    {
    	array[i++] = tko;
    	tko = strtok(NULL, " ");
    }
    array[i] = NULL;
    
    
    
    stat(array[1] , &sb);
    
    if(array[0][1] == 'e' && array[0][0] == '-')
    {
      if(S_ISDIR(sb.st_mode)) // || S_ISREG(sb.st_mode)
      {
           cout << "(TRUE)"<< endl;
            comy.clear();
             
          return 1;
      }
      else 
      {
          cout << "(FALSE)"<< endl;
           comy.clear();
            
          return 1;
      }
      
    }
  
    else if(array[0][1] == 'd' && array[0][0] == '-')
    {
      if(S_ISDIR(sb.st_mode))
      {
           cout << "(TRUE)"<< endl;
            comy.clear();
             
          return 1;
      }
      else 
      {
          cout << "(FALSE)"<< endl;
           comy.clear();
            
          return 1;
      }
     
    }
    
   
    else if(array[0][1] == 'f' && array[0][0] == '-')
    {
      if(S_ISREG(sb.st_mode))
      {
          cout << "(TRUE)"<< endl;
           comy.clear();
            
          return 1;
      }
      else 
      {
          cout << "(FALSE)"<< endl;
           comy.clear();
            
          return 1;
      }
    }
    
    else
    {
      cout << "Unknown flag" <<endl;
       comy.clear();
        
      return 1;
    }
    
    cout << "Error with test!" << endl; 
    comy.clear();
     
   return 1;
}






