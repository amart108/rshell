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
//#include <errno.h>

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
	//cout << "start of the execution" << endl;	
	
	string t = "";
	string t2 = "";
	for(unsigned i = 0; i < cm.length(); i++)
	{
		if(cm.at(i) == ' ')
		{
			t = cm.substr(0,i);
			cm.erase(0,i + 1);
			t2 = cm;
		}
	}
	//cout << "Split the string cm into: " << t << " and " << t2 << endl;
	
	char* d1 = new char[t.length() + 1];
	cout  << d1 << endl;
	strcpy(d1, t.c_str());
	cout << d1 << " and ";
	char* d2 = new char[t2.length() + 1];
	strcpy(d2, t2.c_str());
	cout << d2 << endl;
	char* arg[] = { d1, d2, NULL};	
	//cout << "Put into the char* arg" << endl;	
	
	// do fork and execvp and return when execvp does 
		pid_t  pid = fork();
		if(pid < 0)
		{
			cout << "Fork is not operating.";
			return -1;
		}
		else if (pid > 0)
		{
			int* sit = new int;
			wait(sit);
			if(*sit < 0)
			{
				cout << "Wait in not functioning" << endl;
			}
			else if(*sit == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}	
		else
		{	
			if(execvp(arg[0], arg) < 0)
			{
				cout << "The command failed to execute." << endl;
				return -1;
			}	
			//delete [] arg;
//			delete [] d1;
//			delete [] d2;

		}
		//delete [] arg;
	
		return 0;
	}

};

class Semi: public Base{
protected:
    Base* left;				//command on left(cmd+executable)
    Base* right;			//command on right(cmd+executable)
//    string command_left, command_right;
public:
	Semi(Base* l, Base* r): left(l), right(r) {};
	int execute()
	{	
		cout << "Semi" << endl;
		this->left->execute();
		return this->right->execute();
	}
};

class And: public Base{
protected:
    Base* left;
    Base* right;
    
public:
    And(Base* l, Base* r): left(l), right(r) {};
	int execute()
	{
		cout << "And" << endl;
		this->left->execute();
		/*int result = 0;
		cout << "And" << endl;
		if(this->left->execute() >= 0) 
		{
			 
			
		}
		return result;*/
	
		return 1;;

	}
	
};
class Or: public Base{
protected:
    Base* left;
    Base* right;
public:
    Or(Base* l, Base* r): left(l), right(r) {};
    int execute()
	{
		cout << "1Or" << endl;
		this->left->execute();
		/*if(this->left->execute() < 0)
		{	
			return this->right->execute();
		}
		else
		{
			return 1;
		}*/
		return 7;
	}
};

#endif
