


#include <iostream>
//#include <string>
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
  for (int i=0; i<cons.size(); i++){
    if (cons.at(i)=="&&"){
      AND(i);
    }
     if (cons.at(i)=="||"){
      OR(i);
    }
     if (cons.at(i)==";"){
     	
      SEMI(i);
    }
  }
}

void Executer:: AND(int andpos){
  
  	//Always execute left_command
    
     createproc(segs.at(andpos));
	
	//Only execute right_command if left_Command is 1
	if(mine == 1){
		 createproc(segs.at(andpos+1));
	}
	else {
		return;
	}
  
  
}

void Executer:: OR(int orpos){
  
  	//Always execute left_command
     createproc(segs.at(orpos));
   //  cout << zeus.at(0)<<"within or";
	
	//Only execute right_command if left_Command is 1
	if(mine == 1){

		return;}
	else {
		//cout << zeus.at(0);
		 createproc(segs.at(orpos+1));
		 return;
	}
  
}


void Executer:: SEMI(int semipos){
  
  	//Always execute left_command
  	if (semipos==0){
    createproc(segs.at(semipos));}
	
	//Only execute right_command if left_Command is 1

     createproc(segs.at(semipos+1));
     
     return;
  
  
}




void Executer:: createproc(string comy){


  
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

		cout<< "Child was executed"<< endl;
	    execvp(array[0], array);
	   

		
		
		    cout<< "Failure: Command unknown"<< endl;
		//    kill(pid, SIGKILL);
		    
	
	
		
		
		
		
		exit(1);
	
	
}
else { 
  
   cout<< "Child was waited"<< endl;
		waitpid(pid, &pof, 0);
		if (pof != 0) {
		  mine=0;
	
		}
		else {
		mine =1;	
		}
	}
//zeus.at(0)=0;

 
  cout << "CHILD WAS KILLED"<< endl;

			kill(pid, SIGKILL);
		//	exit (1);

/*if (*zeus.at(0) != 1){
   cout << *zeus.at(0) << endl;
  *zeus.at(0) = 0;
	return 0;
	
	
}*/
 
  //return 0;
}