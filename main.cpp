#include <iostream>
//#include <fstream>
#include <string>
//#include <vector>
//#include "CMD.h"
//#include <cstring>
//#include <sys/wait.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <sys/types.h>
using namespace std;

int main()
{
	string line;
	//cout << "Enter first name and last name: ";
	//getline(cin,name);
	//cout << name << endl;
	cout << "$ ";
	getline(cin, line);
	cout << line << endl;
	cout << line.length() << endl;	/*CMD A("$ ");
	//cout << A.prompt();
	if(argc != 2)
	{
		cout << "Enter name of file.";
		return 0;
	}
	//cout << "Start: " << endl;	
	A.CmdAndCntrs(argv[1]);
	//cout << "checking display: " << endl;
	A.cleanUp();
	A.comment();
	vector<string> s;
	A.cpy(s);
	cout << A.At(3) << endl;
	cout << s.at(3) << endl;
	// this shows how to turn a string into a char*
	string data = s.at(2); // the string here is echo
	char *dat = new char[data.length() + 1]; // this turn the string to char*
	strcpy(dat,data.c_str());
//	cout << dat << endl;
	//A.display();	
	//cout << "Done." << endl;*/
	return 0;
}

