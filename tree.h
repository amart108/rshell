#ifndef TREE_H
#define TREE_H

#include<sys/types.h>
#include<sys/wait.h>
#include <iostream>
#include <string>
#include <unistd.h>
//#include "CMD.h"

using namespace std;

class Base{
public:
    Base(){};
    virtual int execute() = 0;			//pure virtual execute parameter
  //  virtual bool cmd_check(string command) = 0;
};

class Command : public Base{
protected:
	string cm;

public:
	Command(string cm1): cm(cm1) {};
	int execute(){
	// do fork and execvp and return when execvp does 
		int pid = fork();
		if(pid == 0)
		{
			execvp();
		}
		else if(pid < 0 )
		{
			cout << "Error forking" << endl;

		}
		else
		{
			int* status;
			wait(status);
		}
		return -1;
	}
};

class Semi: public Base{
protected:
    Base* left;				//command on left(cmd+executable)
    Base* right;			//command on right(cmd+executable)
//    string command_left, command_right;
public:
	Semi(Base* l, Base* r):left(l), right(r) {};
	int  execute(){	
	return this->right->execute();
	}
};

class And: public Base{
protected:
    Base* left;
    Base* right;
    
public:
    And(Base* l, Base* r): left(l), right(r) {};
	int  execute(){
		if(/* left command doesn't fail */) 
		{ 
			return this->right->execute();
		}
		else{
			//return the failure
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
	if(/*left does not execute */)
	{	
		return this->right->execute();
	}
	else
	{
		//return the failure;
	}
	}
};

#endif
