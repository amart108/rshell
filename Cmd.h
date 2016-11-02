#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <vector>
#include "tree.h"
using namespace std;

class Cmd {
private:
	Base* start;
	string cmdline;// Is the string where the command line is stored
void cleanUp(){ // removes all spaces from the command line and removes everything at and after the # character appears.
	string nline;	
for(unsigned i = 0; i < cmdline.length(); i++)
//nnector: " << connector << ", Left: " << left << ", Right: " << right << endl;
{
		if(cmdline.at(i) == '#'){
		cmdline.erase(i,cmdline.length());
		}   
}

	split();
	//cout << "Done so far" << endl;
}

void split(){ // splits the cmdline by the connector and commands and orangized which commands go to which connectors not complete yer
Base* t;
Base* t2;
vector<int> cnctrs;
//cout << "part one" << endl;
for(unsigned i = 0; i + 1 <  cmdline.length(); i++){
	//cout << cmdline.at(i) << endl;
	if(cmdline.at(i) == ';' || cmdline.at(i) == '&' || cmdline.at(i) == '|'){
		//cout << "Cnctrs list: " << i << endl;
		if(cmdline.at(i + 1) == '&'){
		cnctrs.push_back(i);
		}
		else if(cmdline.at(i + 1) == '|'){
		cnctrs.push_back(i);
		}
		else{
		cnctrs.push_back(i);
		}
	}
		
}

//cout << "Cnctrs: " << cnctrs.size() << endl;
//cout << "Part one done. " << endl;
string left = "";
string right = "";
string connector = "";
int cnt = 0;
//int num = 0;
if(cnctrs.size() == 0)
{
//	cout << "single commands" << endl;
	if(cmdline.find(" ") != string::npos){
		left = cmdline.substr(0,cmdline.find(" "));  }
	cmdline.erase(0,cmdline.find(" "));
	right = cmdline;
	cout << left << endl;
	cout << right << endl;		
	// start = new Command(left, right)
}
else{
//cout << "part two" << endl;
	for(unsigned j = 0; j + 1 < cnctrs.size(); j++){
		if(cnctrs.at(j) != (cnctrs.at(j + 1) - 1)){
//			cout << "Pos: " << cnctrs.at(j) << endl;

//			cout << "cnt: " << cnt << endl;
//			cout << "Cntrs.at(j) " << cnctrs.at(j) << endl;
			if(cmdline.at(cnctrs.at(j)) == ';'){
			left = cmdline.substr(0, cnctrs.at(j));} // When semicolon in the first connector in a multi-command case
			else{
			left = cmdline.substr(0, cnctrs.at(j) - 1);}
			right = cmdline.substr(cnctrs.at(j) + 1, cnctrs.at(j + 1) - cnctrs.at(j) - 1);
			right.erase(0,1);
			if(right.at(right.length() - 1) == ' '){
			right.resize(right.length() - 1);}
			//right.resize(right.length() - 1);

//			cout << left << endl;
//			cout << right << endl;
			if(cmdline.at(cnctrs.at(j)) == ';'){
			//cout << "semi" << endl;
			connector = "semi"; }
			if(cmdline.at(cnctrs.at(j)) == '&'){
			//cout << "And" << endl;
			connector = "and";  }
			if(cmdline.at(cnctrs.at(j)) == '|'){
			//cout << "or" << endl;
			connector = "or"; }
//			cout << connector << endl;
//			cout << left << endl;
//			cout << right << endl;
			t2 = new Command(right);
			cnt += 1;
			cout << "Cnt; " << cnt << endl;
			if(cnt == 1){
			t = new Command(left);
				if(connector == "semi"){
				start = new Semi(t,t2);
				}
				else if(connector == "and"){
				start = new And(t,t2);
				}
				else{
				start = new Or(t,t2);
				}
			}
			else{
				if(connector == "semi"){
				start = new Semi(start,t2);
				}
				else if(connector == "and"){
				start = new And(start,t2);
				}
				else {
				start = new Or(start,t2);
				}
			}
		}	
		cnt += 1;
		if(cmdline.at(cnctrs.at(cnctrs.size() - 1)) == ';'){
		connector = "semi";
		left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)));
		right = cmdline.substr(cnctrs.at(cnctrs.size() - 1));
		right.erase(0,2);
		
		//cout << connector << endl;
		//cout << left << endl;
		//cout << right << endl;
		t2 = new Command(right);
		start = new Semi(start, t2);
		}
		if(cmdline.at(cnctrs.at(cnctrs.size() -1)) == '&'){
		connector = "and";
		//cout << "AND " << endl;
		//cout << "size: " << cnctrs.size() << endl;
		if(cnctrs.size() < 2) {
		//cout << "special case " << endl;
		left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)));}
		else{
		cout << "normal" << endl;
		left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)) - 1); }
		right = cmdline.substr(cnctrs.at(cnctrs.size() - 1) + 1); // if right = & then user must enter another command 
		right.erase(0,1);
		
		if(right == "&"){
			right = ""; 
			cout << "> ";
			getline(cin, right); // need to work when enters nothing and presses enter
		}
		cout << connector << endl;
		cout << left << endl;
		cout << right << endl;
		t2 = new Command(right);
		start = new And(start, t2);
		} // also make sure the both and and or do not remove the last char if they are they only ops with nothing after	
		if(cmdline.at(cnctrs.at(cnctrs.size() -1)) == '|'){
		connector = "or";
		if(cnctrs.size() < 2){
		left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)));}
		else {
		left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)) - 1); }
		right = cmdline.substr(cnctrs.at(cnctrs.size() - 1) + 1);// if right = | then user must enter another command or something
		right.erase(0,1);
		
		if(right == "|"){
			right = "";
			cout << "> ";
			getline(cin, right);
		}
		t2 = new Command(right);
		start = new Or(start, t2);
		//cout << connector << endl;
		//cout << left << endl;
		//cout << right << endl;
		}	
		//cout << "Cnt: " << cnt << endl;
	}
}

}




public:
	
	Cmd() // Constructors takes data form the command line 
	{
		cout << "$ ";
		getline(cin, cmdline);
		//cout << "start clean up" << endl;
		cleanUp();
	}
	void Execute()
	{
		this->start->execute();
	}



};

#endif	
