#ifndef TREE_H
#define TREE_H

using namespace std;

class Base{
private:

public:
    Base();
    virtual void execute()= 0;
    virtual void print_output()= 0;
};

class Connector: public Base{
protected:
    char* argv[];
    Base* left;
    Base* right;
public:
    Connector(): Base();	//default constructor
    void add_command(char*);
    void remove_command(Base* );
    void print_output();
    void execute();
};

class Semi: public Base{
protected:
    Base* left;
    Base* right;
public:
    Semi(): Base();		//default c'tor
    Semi(): Base();		//constructor with numbers of parameters		
    void print_output();
    void execute();
};

class And: public Base{
protected:
    Base* left;
    Base* right;
public:
    And(): Base();		//default c'tor
    And(): Base();		//c'tor with numbers of parameters
    void print_output();
    void execute();
};

class Or: public Base{
protected:
    Base* left;
    Base* right;
public:
    Or(): Base();		//default c'tor
    Or(): Base();		//c'tor with numbers of parameters
    void print_output();
    void execute();
};

class Pound: public Base{
protected:
    char pound;
    vector<Base*> command;
public:
    Pound(): Base();
    void print_output();
    void execute();
};

class Command: Base{
private:
    string cmd;
public:
    Command(): Base();		//default c'tor
    Command(string cmd):Base(); //c'tor with parameter 'cmd'
    void print_output();
    void print_cmdHead(string cmd);
    void print_output();
    void execute();
};
#endif
