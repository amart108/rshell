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
	//A.display();	
	//cout << "Done." << endl;
	return 0;
}

