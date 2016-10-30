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
	commandPrompt = prompt; // get the command prompt: $

}

void CMD::CmdAndCntrs(const string &input_file){
	ifstream fileIn; // get the string from cmdLine.txt file 
	string c1;
	fileIn.open(input_file.c_str());

	if(!fileIn.is_open()){
	cout << "Could not open file" << input_file << "." << endl;
	//return 1;
	}
	
	fileIn >> c1;
	if(c1 == "$"){
	cout << commandPrompt << endl; //Checks if the string pull from the file is the command prompt so it just outputs the command prompt 
	}
	else
	{//this pushes c1 into the string vector stringsep that I created.
		stringSep.push_back(c1);
	}

	while(!fileIn.eof())
	{// this also pushes the rest of the cmdLine.txt file in the vector until 
		fileIn >> c1; // the end of the file has been reached
		if(c1 == "$"){
		cout << commandPrompt << endl;}
		else{
			if(c1 != "end")
			{

				stringSep.push_back(c1);
			}
		}
	}

	fileIn.close();

}

void CMD::display(){
	for(unsigned i = 0; i < stringSep.size(); i++){
		cout <<  stringSep.at(i) << endl;
	}
	cout << endl;
}

void CMD::cleanUp(){// this removes the semi-colon from an element in the vector and inserts it an an element after the element it was removed from
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

void CMD::comment(){// this removes anything from the command line after the # has appeared in the command line
for(unsigned i = 0; i < stringSep.size(); i++)
{
	//char t = '#';
	if(stringSep.at(i)== "#")
	{

		stringSep.erase(stringSep.begin() + i, stringSep.end());
	}			
}
}

string CMD::At(int i){ // this allow the users to get an elements from the vector
return stringSep.at(i);
}
