#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

class Base{
public:
    Base(){};
    virtual void execute(string command) = 0;			//pure virtual execute parameter
    virtual bool cmd_check(string command) = 0;
};

class Connector: public Base{
protected:
    string command;
public:
    Connector(): Base(){};
    Connector(string command): Base(){
	this->command = command;
    };
    Connector(Base* left, Base* right): Base(){ //c'tor overloading with 				
	this->left = left;			//left(cmd+executable) + right(cmd + executable)
	this->right = right;
    };
    bool cmd_check(){			
			//... split string command into two part(cmd + executable) and check those are valid
	if(left is one of commands)
	{
	    if(right is one of executables){
		return true;
	    }
	    else{
		cout << "Input valid command"<<endl;
		return false;
	    }
	}
	else{
	    cout<<"Input valid command"<<endl;
	    return false;
	}
    };

    void execute(){			//execute definition
	if(this->command->cmd_check() == true){
	   //execute
	}
    }
};    

class Semi: public Base{
protected:
    Base* left;				//command on left(cmd+executable)
    Base* right;			//command on right(cmd+executable)
    string command_left, command_right;
public:
    Semi(): Base(){};			//default c'tor
    Semi(Base* left, Base* right, string command1, string command2): Base(){
	this->left = left;		//c'tor with two parameter which is separated in cmd+executable
	this->right = right;
	this->command_left = command1;
	this->command_right = command2;
    };
    bool cmd_check(){
	this->command_left->cmd_check();
	this->command_right->cmd_check();
    }
    bool cmd_exe_check(){
	this->left->cmd
    void execute(string command){			//both left and right will be executed no matter what
	right->execute();		//if invalid cmd executed, error message will appear.
	};
};

class And: public Base{
protected:
    Base* left;
    Base* right;
    
public:
    And(): Base(){};			//default c'tor
    And(Base* left, Base* right): Base(){
	this->left = left;		//c'tor with two parameter which is separated in cmd+executable
	this->right = right;
    };
    
    };
    void execute(){
	if(cmd_check(left) == true){
	    right->execute();		//true means executed(with valid command)
	else if(cmd_check(left) != true)//use bool function return true or false if command is executed or not
	    return;			//we need two bools(one bool per each command which can be overwritten
	}
    };
};
class Or: public Base{
protected:
    Base* left;
    Base* right;
public:
    Or(): Base(){};			//default c'tor
    Or(Base* left, Base* right): Base(){
	this->left = left; 		//c'tor with two parameter which is separated in cmd+executable
	this->right = right;
    };
    void execute(){
	if(cmd_check(left) != true){	//false means not executed(with invalid command)
	    right->execute();
	}
	else if(cmd_check(left) == true){
	    return;
    };
};
