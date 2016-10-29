#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "PartOfString.h"

using namespace std;

class CMD
{
        private:
 //      vector<POS> stringSep;
	vector<string> stringSep;
	string commandPrompt;
	//string piece;
	public:
	CMD();
	CMD(string prompt);	
	void CmdAndCntrs(const string &input_file);
	void display();
	void cleanUp();	
	void comment();
//void clean(vector<string> &c);
};
#endif

