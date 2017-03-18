


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
 

    for (int i=0; i<segs.size(); i++){
        cout << segs.at(i)<< "  ";
    }
    
    cout <<endl;
    
    
    
    //    cout <<segs.at(andpos)<< " Im her 1" ;
    if (segs.size()> 0){
   }
	
  for (unsigned int i=0; i<cons.size(); i++){
     // cout<< cons.at(i)<< "    "<< i <<endl;
      
  	
if (segs.at(i)=="exit"){
	comy="exit";
	
	return;
}
 if (cons.at(0) != ">" && cons.at(0) != ">>" && cons.at(0)!= "<"&& cons.at(0)!= "|"){
  if (i==0) {
       createproc(segs.at(0));
     comy.clear();
    }
 }
 
 
 
 
  if ((i+1<cons.size() && cons.at(i+1)==">") || (cons.size()==2 && cons.at(i)==">")){
   
   if (cons.at(0) == ">" && i==0){
  //  cout << " Output file runninghere"<< endl; output file is the first
  outputFile(i+1);
       createproc(segs.at(0));
     comy.clear();
    
 }
   
   else { 
    //output file not first
    // 	cout << "OUTPUT FILE RUN" << endl;
     
     if (i+2<cons.size()){
     
      outputFile(i+2);}
      
      
    
      
       if  (i>0 && (cons.at(i-1) == ">" || cons.at(i-1) == ">>" || cons.at(i- 1) == "|" || cons.at(i-1) == "<")) {
     
         createproc(segs.at(i-1));
     
      comy.clear();
      
        }
        
   
   }
}

   


     if ((i+1<cons.size() && cons.at(i+1)==">>") || (cons.size()==2 && cons.at(i)==">>")){
     	
     	 if (cons.at(0) == ">>" && i==0){
     //	  cout << "OUTPUT FILE RUN SINGLE" << endl; //if ow is the first
    outputFileOverwrite(i+1);
       createproc(segs.at(0));
    comy.clear();
   
 }
   
   else {
    // 	cout << "OUTPUT FILE RUN OW" << endl; //if multiple commands and ow is not the first
      outputFileOverwrite(i+2);
      if (i-1 != 0 && (cons.at(i-1) == ">" || cons.at(i-1) == ">>" || cons.at(i-1) == "|" | cons.at(i-1) == "<") ){
        createproc(segs.at(i-1));
     comy.clear();}
   }
     	
     
    }
    
  	   
  // cout << cons.at(0) << endl; 	 
   if (cons.at(0) == "<" && i==0){
    
  //  cout << "input file running single" << endl;
    inputFile(1);
  //  cout << "afters ice cream" << endl;
    createproc(segs.at(0));
    comy.clear();
    
 }
   else if(i<cons.size()-1 && i+1<cons.size() && cons.at(i+1)=="<") {
   //  	cout << "INPUT FILE RUN";
      inputFile(i+2);
   //   cout << "afters ice cream";
      // I now want ice cream
      if (i>0 && (cons.at(i-1) == ">" || cons.at(i-1) == ">>" || cons.at(i-1) == "|" | cons.at(i-1) == "<") ){
        createproc(segs.at(i-1));
     comy.clear();
       
      }
   }
       
    
 
 
    
    
    
    
    if ((i+1<cons.size() && cons.at(i+1)=="|") || (cons.size()==2 && cons.at(i)=="|")){
     	  	 
   if (cons.at(0) == "|" && i==0){
   // cout << " input output file running single"<< endl;
    pipecounter=0;
    x=i;
   while (cons.at(x) == "|" && x<cons.size() ){
     pipecounter=pipecounter+1;
     x=x+1;
    }
  //  cout << pipecounter << "pipecounter" << endl;
    outtoin(i, pipecounter);
     //  createproc(segs.at(0));
     comy.clear();
    
    
     }
   
  /* if (i+1<cons.size() && cons.at(i+1)=="|") {
     	cout << "INPUT OUTPUT FILE RUN multiple" << endl;
    outtoin(i+1);
   }*/
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
    
    
     if ((i+1<cons.size() && cons.at(i+1)==">") || (cons.size()==2 && cons.at(i)==">") || 
        (i+1<cons.size() && cons.at(i+1)==">>") || (cons.size()==2 && cons.at(i)==">>") ){
     
      closeFile();
      //continue;
    }
    
  
    
    if ((i<cons.size()-1 && i+1<cons.size() && cons.at(i+1)=="<") || (cons.size()>=2 && cons.at(0)=="<" && i==0))
    {
    
     //cout << "file closed";
   
     closeinFile();
    // continue;
    }
    
     if ((i+1<cons.size() && cons.at(i+1)=="|") || (cons.size()==2 && cons.at(i)=="|"))
    {
     
     closeinoFile();
   //  continue;
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

void Executer:: outputFile(int filepos){ // >
 
 
 
 saved_stdout = dup(1);
 
 // remove spaces from file name

  filenameoutput= segs.at(filepos);
 for (unsigned b=0; b<filenameoutput.size(); b++){
  if (filenameoutput.at(b)==' ')
  filenameoutput.erase(b, b+1);
 }
 //cout <<filenameoutput <<endl;
 
 out = open(filenameoutput.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR | S_IXUSR | S_IXGRP);

 dup2(out, 1);
 
 close(out);
//cout << "6 "<< endl;
 
 
 
}

void Executer::inputFile(int filepos){ // 




 saved_stdin = dup(0);
  filenameinput= segs.at(filepos);
  
  
  for (unsigned b=0; b<filenameinput.size(); b++){
  if (filenameinput.at(b)==' ')
  filenameinput.erase(b, b+1);
 }
 // cout << filenameinput<<endl;
  // open input file here
  
 in = open(filenameinput.c_str(), O_RDONLY, 0);
 // cout << in << endl;
 dup2(in, STDIN_FILENO);
 close(in);
 // finished input
 //cout << "finished in put"<< endl;
// cout << "7 "<< endl;
 
 
}




void Executer:: closeFile(){ // >
 // restore for return to terminal output
dup2(saved_stdout, 1);
close(saved_stdout);

 
}

void Executer:: closeinFile(){ // >
 // restore for return to terminal input
dup2(saved_stdin, 0);
close(saved_stdin);

 
}
void Executer:: closeinoFile(){ // >
 
dup2(saved_stdin, 0);
close(saved_stdin);
dup2(saved_stdout, 1);
close(saved_stdout);
}

void Executer:: outputFileOverwrite(int filepos){
 
  // save for return to terminal output
 saved_stdout = dup(1);
 
 

  filenameoutput= segs.at(filepos);
 
 // open file w/ proper permissions creates if its missing
 out = open(filenameoutput.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR | S_IXUSR | S_IXGRP);

 dup2(out, 1);
 
 close(out);

 
 
 
 
}


void Executer:: outtoin(int filepos, int pipecounter){
 
  filein=0;
   int  piped[2];
   
 
  cmcount=0;

  while (cmcount <=pipecounter)
    {
      pipe(piped);
      if ((pid = fork()) == -1)
        {
          exit(1);
        }
      else if (pid == 0)
        {
          dup2(filein, 0); //change input to old
          if (cmcount  != pipecounter)
            dup2(piped[1], 1);
          close(piped[0]);
        createproc(segs.at(filepos+cmcount));
          exit(1);
        }
      else
        {
          wait(NULL);
          close(piped[1]);
          filein = piped[0]; //next in[put ] command
          cmcount++;
        }
    }


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
       }


	if (pid == 0) {

//		cout<< "Child was executed"<< endl;



 
	    execvp(array[0], array);
	   

		
		
		    cout<< "Failure: Command unknown"<< endl;
		exit(1);
	
	
}
else { 
		waitpid(pid, &pof, 0);
		if (pof != 0) {
		  mine=0;
	
		}
		else {
		mine =1;	
		}
			kill(pid, SIGKILL);
}

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






