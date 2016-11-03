#ifndef TREE_H
#define TREE_H

#include<sys/types.h>
#include<sys/wait.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
//#include <array>
//#include <errno.h>

//#include "CMD.h"

using namespace std;

class Base{
public:
    Base(){};
    virtual int execute() = 0;			//pure virtual execute parameter
						//  virtual bool cmd_check(string command) = 0;
};

class Command : public Base{			//Leaf class which actually executes 
protected:					//input commands.
    string cm;				//command as string variable
public:
    Command(string cm1): cm(cm1) {};
    int execute() 				// executes a sing commamnd like ls, 
    {					//ls -a, echo hello, and so on
	string t = "";
	string t2 = "";
	//cout << "Cm:" << cm << endl;
	for(unsigned i = 0; i + 1 < cm.length(); i++)
	{
	    if(cm.at(i) == ' ')
	    {
		t = cm.substr(0,i);
		cm.erase(0,i + 1);
		t2 = cm;
		
		if(t2.at(t2.length() - 1) == ' ')
		{
		    t2.erase(t2.length() -1,1);
		}
	    }
	    else
	    {
		t = cm;
	    }
	}
		//cout << "Split the string cm into: " << t << " and" << t2 << endl;
		
	char* d1 = new char[t.length() + 1];
	strcpy(d1, t.c_str());
		
	char* d2 = new char[t2.length() + 1];
	strcpy(d2, t2.c_str());
		
	char* arg[] = { d1, d2, NULL};	
			//cout << "Checking arg: "  << arg[0] << " and " << arg[1] << endl;
					//cout << "Put into the char* arg" << endl;	
	pid_t pid = fork();	// do fork and execvp and return when execvp does 
	if(pid < 0)
	{			//if pid<0 child is not 0
	    perror( "Fork is not operating."); // child is a zombie
	    exit(1);
	}
	else if (pid > 0)
	{
	    int* sit = new int;
	    wait(sit);
	    
	    if(*sit < 0)
	    {
		perror("Wait in not functioning");
		exit(1);
	    }
	    else if(*sit == 0)
	    {
		return 1;
	    }
	    else
	    {
		return 1;
	    }
	}	
	else
	{	
	    if(execvp(arg[0], arg) < 0) 	//if command is not valid(bad)
	    {
		perror( "The command failed to execute.");
						//we don't run the command
		exit(1);
	    }	
	    exit(0);
	}
	return 0;	
    }
};

class Semi: public Base{ 		// this class happends when there is a ";" connector
protected:
    Base* left;				//command on left(cmd+executable)
    Base* right;			//command on right(cmd+executable)

public:
    Semi(Base* l, Base* r): left(l), right(r) {};
    int execute() 			// executes both commands
    {	
		//cout << "Semi" << endl;
	this->left->execute();	
	this->right->execute();
	return 1;
    }
};

class And: public Base{ 	// this is created when there is a && between two connectors
protected:
    Base* left;
    Base* right;
    
public:
    And(Base* l, Base* r): left(l), right(r) {};
    int execute() 			// This checks if the left command executed 
    {				//properly is it did then it executes
		//cout << "And" << endl;//the right command if not it return -1;		
	this->left->execute();
	if(this->left->execute() > 0)
	{
		//cout << "Right" << endl;	
	    return this->right->execute(); 	
	}
	else
	{
	    return -1;
	}
    }
};
class Or: public Base{
protected:
    Base* left;
    Base* right;
public:
    Or(Base* l, Base* r): left(l), right(r) {};
    int execute(){
	//cout << "Or" << endl;
	//this->left->execute();
	if(this->left->execute() < 0)
	{	
	    return this->right->execute();
	}
	else
	{
	    return 1;
	}
    }
};

#endif
