#include <iostreamr>
#include <vector>
#include <string>
#include <unistd>

using namespace std;

class Base{
private:
    
public:
    Base(){};
    virtual void execute() = 0;		//pure virtual
    virtual void print_output()=0;		//pure virtual
};

class Connector: public Base{
protected:
    char* argv[];
    Base* left;
    Base* right;
public:
    Connector(): Base(){};
    Connector(): Base(){
    };
    
    void add_command(char* argv[]){
	this->argv = argv;
    };

    void remove_command(Base* command){
	for(unsigned i = 0; i < command.size(); i++){
	    if(command == this->command.at(i))
		this->command.erase(this->command.begin() + i);
		return;
	    }
	}
    };
    void print_output(){
	for(unsigned i = 0; i < command.size(); i++){
	    command.at(i)->print_output();
	}
    };
};

class Semi: public Base{
protected:
    Base* left;
    Base* right;
public:
    Semi(): Base(){};
    Semi(): Base(){
    };
    void print_output(){
	
    };
    void execute(){		//both left and right will be executed
	left->execute();	//need to make childs to '0'
	right->execute();
    };
};

class And: public Base{
protected:
    Base* left;
    Base* right;
    
public:
    And(): Base(){};
    And(): Base(){
    };
    void print_output(){
    
    };
    void execute(){
	if(left == true){	//true means executed(with valid command)
	right->execute();	//use bool function return true or false if command is executed or not
				//we need two bools(one bool per each command which can be overwritten
	}
    };
};
class Or: public Base{
protected:
    Base* left;
    Base* right;
public:
    Or(): Base(){};
    Or(): Base(){
    };

    void print_output(){
    
    };
    void execute(){
	if(left == false){	//false means not executed(with invalid command)
	right->execute();
	}    
    };
};

/*
class Pound: public Base{
protected:
    char pound = '#';
    vector <Base*> command;
public:
    Pound(): Base(){};

    void print_output(){
    };

    void execute(){
	for(un
*/

class Command: Base{
private:
    string cmd;
public:
    Command(): Base(){};
    Command(string cmd): Base(){
	this->cmd = cmd;
    };/*
    void print_cmdHead(string cmd){
	cout<<"$ ";
	getline(cin,cmd);		//do we need getline(cin, cmd)? or just cin?
    };
    void print_output(){
	if(cmd == true){		//need to add verifying cmd(with header function)
	execute();
	}
	else(cmd == false){
	cout<< "Invalid command, try again
*/
