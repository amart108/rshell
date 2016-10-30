#include <iostream>
#include "CMD.h"
#include <vector>
#include <string>

using namespace std;

CMD::CMD()
{
	commandPrompt = "";
}

CMD::CMD(string prompt)
{
	commandPrompt = prompt;

}

void CMD::CmdAndCntrs(const string &input_file){

	ifstream fileIn;
	string c1;
//	string c2;
//	string c3;
	fileIn.open(input_file.c_str());
	if(!fileIn.is_open()){
	cout << "Could not open file" << input_file << "." << endl;
	//return 1;
	}
	
	fileIn >> c1;
	if(c1 == "$"){
	cout << commandPrompt << endl;
	}
	else
	{
		stringSep.push_back(c1);
	}
	//stringSep.push_back(POS(c1,c2));
	//stringSep.push_back(c2);
	//cout << "Before next line" << endl;
	while(!fileIn.eof())
	{
	//	cout << "Next Line " << endl;
		fileIn >> c1;
		if(c1 == "$"){
		cout << commandPrompt << endl;}
		else{
			if(c1 != "end")
			{
//			cout << commandPrompt << endl;
				stringSep.push_back(c1);
			//stringSep.push_back(POS(c1,c2));
//		stringSep.push_back(c2);
			}
		}
	}

	fileIn.close();

}

void CMD::display(){
	for(unsigned i = 0; i < stringSep.size(); i++){
	//	char t = '$';
		//cout << commandPrompt;
		//cout << i << ": ";
		cout <<  stringSep.at(i) << endl;
	}
	cout << endl;
}

void CMD::cleanUp(){
vector<string>temp;


for(unsigned i = 0; i < stringSep.size(); i++){

	char t = ';';
	temp.push_back(stringSep.at(i));

	for(unsigned j = 0; j < stringSep.at(i).length(); j++)
	{	
		if(stringSep.at(i).at(j) == t)
		{
			string semi = ";";
			stringSep.at(i).erase(j,1);
			temp.pop_back();
			temp.push_back(stringSep.at(i));
			temp.push_back(semi);		
		}
	}
}
stringSep = temp;
}

void CMD:: comment(){
for(unsigned i = 0; i < stringSep.size(); i++)
{
	//char t = '#';
	if(stringSep.at(i)== "#")
	{

		stringSep.erase(stringSep.begin() + i, stringSep.end());
	}			
}
}
