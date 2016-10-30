#include <iostreamr>
#include <vector>
#include <string>
#include <unistd>

using namespace std;

class Base{
public:
    Base(){};
    virtual void execute() = 0;			//pure virtual execute parameter
    virtual bool cmd_check()
};

class Connector: public Base{
protected:
    char* argv[];
    bool left_bool, right_bool;
public:
    Connector(): Base(){};
    Connector(): Base(){
    };
    bool cmd_check(left, right){
	if(left_bool == true){
	    if(right_bool == true){
		execute(argv);
	    }
	    else{
		    cout << "Error message"<<endl;
	    }
	else{
	    cout<<"Error message"<<endl;
	}
    };
// 	return true ,if cmd is true
    
    void execute(char* argv){
	    execute(argv);
    }
// return true if cmd is excuted 
    
};

class Semi: public Base{
protected:
    Base* left;
    Base* right;
    char* argv[];
public:
    Semi(): Base(){};
    Semi(Base* left, Base* right): Base(){
	this->left = left;
	this->right = right;
    };
	
    bool cmd_exe_check(){		//check command is executed
    if(true){
	return true;

    void execute(){			//both left and right will be executed
	if(cmd_check() == true){	//
	    argv[]->execute();		
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
	if(cmd_exe_check(left) == true){
	    right->execute();	//true means executed(with valid command)
	    			//use bool function return true or false if command is executed or not
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

class Command: Base{
private:
    string cmd;
public:
    Command(): Base(){};
    Command(string cmd): Base(){
	this->cmd = cmd;
    };
