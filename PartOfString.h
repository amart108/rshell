#ifndef PARTOFSTRING_H
#define PARTOFSTRING_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class POS{
protected:
	string line;
	string prt1;
	string prt2;
	//string prt3;
	vector<string> CmdLine;
	
public:
	POS();
	POS(const string& p1, const string& p2);
	void child();
	//void split(string nline);
	//string getCommand() const;
	//string getConnector() const;
};

#endif 
