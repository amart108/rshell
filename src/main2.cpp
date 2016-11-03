#include "tree.h"
#include <iostream>
#include <string>
#include <vector>
#include "Cmd.h"
using namespace std;

int main()
{
	Cmd car;
	car.Execute();
	
	return 0;

}


/*	string line;
	cout << "$ ";
	getline(cin,line);
	
	string nline;

	unsigned s = line.length();
	for(unsigned i = 0; i < s; i++)
	{
		if(line.at(i) == '#')
		{
			line.erase(i,line.length());
		}
	//	if(line.at(i) != ' '){
	//	nline.push_back(line.at(i));
	
	//	}
	}
//	line = nline;
//	string SEMI;
//	string AND;
//	string OR;

	//int a = 0;
	//int b = 0;
	//cout << "line: " << line << endl << endl;
	vector<int> cnctrs;
	for(unsigned j = 0; j + 1 < line.length(); j++){
		if(line.at(j) == ';' || line.at(j) == '&' || line.at(j) == '|'){
			if(line.at(j + 1) == '&'){
			cout << "AND: " << j << endl;
			cnctrs.push_back(j);
			}
			else if( line.at(j + 1) == '|'){
			cnctrs.push_back(j);
			cout << "OR: " << j << endl;
			}
			else
			{ 
			cnctrs.push_back(j); 
			cout << "SEMI: " << j << endl;
			}
		}
		
	}
	
	string left;
	string right;
	string connector;
//	int t = 0;
	for(unsigned  k = 0; k + 1 < cnctrs.size(); k++)
	{
		if(cnctrs.at(k) != (cnctrs.at(k + 1) - 1))
		{	
			cout << "Pos: " << cnctrs.at(k) << endl;
			if(line.at(cnctrs.at(k)) == ';'){
			left = line.substr(0, cnctrs.at(k));
			}
			else{
			left = line.substr(0, cnctrs.at(k) - 1);}
			right = line.substr(cnctrs.at(k) + 1,cnctrs.at(k + 1) - cnctrs.at(k) - 1 );			
			cout << left << endl;
			cout << right << endl;
			if(line.at(cnctrs.at(k)) == ';')
			{
				connector = "semi";
			}
			if(line.at(cnctrs.at(k)) == '&')
			{
				connector = "and";
			}
			if(line.at(cnctrs.at(k)) == '|')
			{
				connector = "or";
			}
			cout << connector << endl;
		}
	}
	if(line.at(cnctrs.at(cnctrs.size() - 1)) == ';'){
	connector = "semi";
	left = line.substr(0, (cnctrs.at(cnctrs.size() - 1)));
	cout << left << endl;
	right = line.substr(cnctrs.at(cnctrs.size() - 1));
	right.erase(0,1);
	
	cout << right << endl;

	}	
	else if(line.at(cnctrs.at(cnctrs.size() - 1)) == '&'){
	connector = "and";
	left = line.substr(0, (cnctrs.at(cnctrs.size() - 1)) - 1);
	right = line.substr(cnctrs.at(cnctrs.size() - 1) + 1);
	cout << left << endl;
	cout << right << endl;
	}
	else{
	connector = "and";
	left = line.substr(0, (cnctrs.at(cnctrs.size() - 1)) - 1);
	right = line.substr(cnctrs.at(cnctrs.size() - 1) + 1);
	cout << left << endl;
	cout << right << endl;
	}

*/
