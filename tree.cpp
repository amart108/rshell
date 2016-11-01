#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

class Base{
public:
    Base(){};
    virtual void execute(string command) = 0;		//pure virtual execute function
    virtual bool valid_check(string command) = 0;	//check command is valid or invalid
};							//we regard bad commands as Not executed command

class Connector: public Base{ 
protected:
    string command;
public:
    Connector(): Base(){};
    Connector(string command): Base(){
	this->command = command;
    };
    bool valid_check(string command){			//check the command is good or bad.
	if(command == valid){				//... command validity check
	    return true;
	}
	else{
	    return false;
	}
    };

    void execute(){					//execute definition
	if(valid_check(string command) == true){	//If it's a valid command
	   right -> execute();				//will executed
	}
	else{						//if it's invalid, print "Invalid command"
	    cout<< "Invalid command"<<endl;
        }
    }
};    

class Semi: public Base{
protected:
    Base* left;						//command on left
    Base* right;					//command on right
    string command;					//right command for valid check
public:
    Semi(): Base(){};					//default c'tor
    Semi(Base* left, Base* right, string command): Base(){
	this->left = left;				//c'tor with three parameters which are left
	this->right = right;				//right command and a command for check validty
	this->command = command;
    };
    bool valid_check(string command){			//check validity
        if(command == valid){
            return true;
        }
        else{
            return false;
        }
    };

    void execute(){					//both left and right will be executed
	if(valid_check(string command) == true){	//no matter what
	    right->execute();				//if invalid cmd executed, 
    	}						//error message will appear.
	else{
	    cout << "Invalid command"<<endl;
	}
    };
};

class And: public Base{
protected:
    Base* left;
    Base* right;
    string command;
public:
    And(): Base(){};					//default c'tor
    And(Base* left, Base* right, string command): Base(){
	this->left = left;				//c'tor with three parameter which are left,
	this->right = right;				//right command and command for check validity
	this->command = command;
    };
    bool valid_check(string command){			//check validity
	if(command == valid){
	    return true;
	}
	else{
	    return false;
	}
    };

    bool cmd_exe_check(Base* left){			//cmd exe check "&&"
	if(left->execute()){				//if left(cmd+executable)executed, return true
	    return true;				//other case, return false
	}
	else
	    return false;
	}
    };

    void execute(){
	if(cmd_exe_check(left) == true){
	    if(valid_check(string command) == true){
	        right->execute();			//if left executed, and valid command
	    }						//command will be executed
	    else{ 			
	        cout << "Invalid command"<<endl;	//left executed but invalid command 
	    }						//print "Invalid command"
	}						//if left is not executed, execute/print Nothing
	else{
	    return;	
	}  
    };
};

class Or: public Base{
protected:
    Base* left;
    Base* right;
    string command;
public:
    Or(): Base(){};					//default c'tor
    Or(Base* left, Base* right, string command): Base(){
	this->left = left; 				//c'tor with three parameters which are left,
	this->right = right;				//right command and command for check validity
	this->command = command;
    };
    
    bool valid_check(string command){			//check validity
	if(command == valid){
	    return true;
	}
	else{
	    return false;
	}
    };
    
    bool cmd_exe_check(Base* left){			//cmd exe check "||" 
	if(left->execute()){				//if left(cmd+executable) executed, return false
	    return false;				//other case, return true;
	else
	    return true;
    };

    void execute(){
	if(cmd_exe_check(left) != true){		//if left is not executed, and valid command
	    if(valid_check(string command){		//command will be executed
		right->execute();
	    }
	    else{
		cout<< "Invalid command"<<endl;		//if left is not executed, and invalid command
	    }						//print "Invalid command"
	}						//if left is executed, execute/print Nothing
	else{
	    return;
	}
    };
};

