#include "PartOfString.h"
#include <string>
#include <iostream>

using namespace std;

POS::POS(){
	line = "";
	prt1 = "";
	prt2 = "";
//	prt3 = "";
	return;
}


POS::POS(const string& p1, const string& p2){
	prt1 = p1;
//	CmdLine.push_back(p1);
	prt2 = p2;
//	CmdLine.push_back(p2);
//	prt3 = p3;
	line = p1 + " " + p2;// + " " + p3;;
	return;
}

void POS::child()
{
//	cout << CmdLine.size() << endl;
//for(unsigned i = 0; i < CmdLine.size(); i++){
//		cout << i << ": " <<  CmdLine.at(i);
//	}
}

						
