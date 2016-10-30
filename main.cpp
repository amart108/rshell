#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CMD.h"
#include <cstring>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char*argv[])
{
	CMD A("$ ");
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
	// this shows how to turn a string into a char*
	string data = A.At(2); // the string here is echo
	char *dat = new char[data.length() + 1]; // this turn the string to char*
	strcpy(dat,data.c_str());
	cout << dat << endl;
	//A.display();	
	//cout << "Done." << endl;
	return 0;
}

