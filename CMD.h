#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class CMD
{
        protected:
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
	string At(int i);
	void cpy(vector<string> &s);
//void clean(vector<string> &c);
};
#endif

