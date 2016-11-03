#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "tree.h"
using namespace std;

class Cmd {
protected:
	Base* start;
	string cmdline;// Is the string where the command line is stored
void cleanUp(){ // removes all spaces from the command line and removes everything at and after the # character appears.
	string nline;	
	for(unsigned i = 0; i < cmdline.length(); i++)
	{
		if(cmdline.at(i) == '#')
		{
		cmdline.erase(i,cmdline.length());
		}   
	}

	split();

}
/*Base* subConnect(vector<int> c, string l)
{
	for(unsigned i - 1 < c.size(); i  = 0; i--)
*/		
void split()
{ // splits the cmdline by the connector and commands and orangized which commands go to which connectors not complete yer
Base* t;
Base* t2;
//Base* t3;
//Base* t4;
vector<int> cnctrs;
//cout << "WHYYYYYYYYY" << endl;
for(unsigned i = 0; i <  cmdline.length(); i++)
{
//cout << "i: " << i << " word: " << cmdline.at(i) << endl;
	if(cmdline.at(i) == ';' || cmdline.at(i) == '&' || cmdline.at(i) == '|')	
	{

		if(cmdline.at(i) == '&')
		{
			cnctrs.push_back(i);
//cout << "pushed &" << endl;
		}
		else if(cmdline.at(i) == '|')
		{
			cnctrs.push_back(i);
//	cout << "pushed |" << endl;
		}
		else
		{
//		cout << "check";
			cnctrs.push_back(i);
//	cout << "pushed ;" << endl;
//		cout << "mate" << endl;
		}
//	cout << "one" << endl;
	}
//	cout << "two" << endl;	
}

//cout << "three" << endl;
string left = "";
string right = "";
string connector = "";
int cnt = 0;

if(cnctrs.size() == 0)
{
//	cout << "single commands" << endl;
	start = new Command(cmdline);
//	cout << "done with singles" << endl;

}
else
{
	if(cnctrs.size() > 1)
	{
//		cout << "4" << endl;
		for(unsigned j = 0; j + 1 < cnctrs.size(); j++)
		{
			//cout << "J: " << j << ", " << cnctrs.at(j) << ", " << cmdline.at(cnctrs.at(j)) << endl;
			//cout << "next: " << j + 1 << ", " << cnctrs.at(j+1) - 1 << ", "  <<  cmdline.at((cnctrs.at(j + 1))) << endl;
			if(cmdline.at(cnctrs.at(j)) != cmdline.at((cnctrs.at(j + 1))))
			{
				//cout << "5" << endl;
				if(cmdline.at(cnctrs.at(j)) == ';')
				{
					left = cmdline.substr(0, cnctrs.at(j));
				} // When semicolon in the first connector in a multi-command case
				else
				{
					left = cmdline.substr(0, cnctrs.at(j) - 1);
					Exit(left);
				}
				right = cmdline.substr(cnctrs.at(j) + 1, cnctrs.at(j + 1) - cnctrs.at(j) - 1);
				right.erase(0,1);
				if(right.at(right.length() - 1) == ' ')
				{
					right.resize(right.length() - 1);
				}
				if(cmdline.at(cnctrs.at(j)) == ';')
				{
						connector = "semi"; 
				}
				if(cmdline.at(cnctrs.at(j)) == '&')
				{
					connector = "and";  
				}
				if(cmdline.at(cnctrs.at(j)) == '|')
				{
					connector = "or"; 
				}
				Exit(right);
//				cout  << "makeing connectors" << endl;
//			cout << "problems" << endl;
				t2 = new Command(right);
//			cout << connector << endl;
				t = new Command(left);
			//	cout << "6" << endl;
				if(cnt  == 0)
				{
					cout << "7" << endl;
					if(connector == "semi")
					{
						start =  new Semi(t,t2);
					}
					else if(connector == "and")
					{
						start =  new And(t,t2);
					}
					else
					{
						start = new Or(t,t2);
					}
				
				}
				else
				{
			//		cout << "8" << endl;
			//		cout << "OThers; " << endl;	
					if(connector == "semi")
					{
						start = new Semi(start,t2);
					}
					else if(connector == "and")
					{
						start = new And(start,t2);
					}	
					else 
					{
						start = new Or(start,t2);			
					}		
			
			
				}	

			}
			else
			{
				//cout << "9" << endl;

				if(cmdline.at(cnctrs.at(j + 1)) == '&')
				{
			//		Base* t3 = new Command("ls -a");
			//		Base* t4 = new Command("echo hello");
			//		Base* t5 = new Semi(t3,t4);
			//		cout << "10" << endl;
					right = cmdline.substr(cnctrs.at(j + 1) + 1);
					//cout << "Left: " << left << endl;
					//, cnctrs.at(j + 1) - cnctrs.at(j) - 1);	
					right.erase(0,1);
					Exit(left);
					Exit(right);
					//cout << "Right: " << right << endl;
					if(right.at(right.length() - 1) == ' ')
					{
						right.resize(right.length() - 1);
					}
					connector == "and";
					t2 = new Command(right);
					start = new And(start,t2);				
				}	
				else
				{
//					cout << "11" << endl;
					right = cmdline.substr(cnctrs.at(j) + 1);
                                        right.erase(0,1);
                                        if(right.at(right.length() - 1) == ' ')
                                        {
                                                right.resize(right.length() - 1);
                                        }
					Exit(right);
					connector == "Or";
					t2 = new Command(right);
					start = new Or(start, t2);
				}
//				cout << "j: " << j << endl;
//				cout << "j + 1: " << j + 1 << endl;
			

			}
		}	
	
	}	
//		cout << "7" << endl;
	cnt += 1;
	if(cmdline.at(cnctrs.at(cnctrs.size() - 1)) == ';')
	{
	//	cout << "one semi" << endl;
		connector = "semi";
		left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)));
		right = cmdline.substr(cnctrs.at(cnctrs.size() - 1));
		right.erase(0,2);
		Exit(left);
		Exit(right);	
			//cout << connector << endl;
			//cout << left << endl;
		//cout << right << endl;
		t2 = new Command(right);
		t = new Command(left);
		start = new Semi(t, t2);
	}
	if(cmdline.at(cnctrs.at(cnctrs.size() -1)) == '&')
	{
		connector = "and";
			//cout << "AND " << endl;
				//cout << "size: " << cnctrs.size() << endl;
		if(cnctrs.size() < 2) 
		{
	//	cout << "special case " << endl;
			left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)));
		}
		else
		{
	//	cout << "normal" << endl;
			left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)) - 1); 
		}
		right = cmdline.substr(cnctrs.at(cnctrs.size() - 1) + 1); // if right = & then user must enter another command 
		right.erase(0,1);
		Exit(left);
		Exit(right);	
		if(right == "&")
		{
			right = ""; 
			cout << "> ";
			getline(cin, right); // need to work when enters nothing and presses enter
		}
	//	cout << connector << endl;
	//	cout << left << endl;
	//	cout << right << endl;
		t2 = new Command(right);
		t = new Command(left);
		start = new And(t, t2);
	} // also make sure the both and and or do not remove the last char if they are they only ops with nothing after	
	if(cmdline.at(cnctrs.at(cnctrs.size() -1)) == '|')
	{
		connector = "or";
		if(cnctrs.size() < 2)
		{
			left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)));
		}
		else 
		{
			left = cmdline.substr(0, (cnctrs.at(cnctrs.size() - 1)) - 1); 
		}
		right = cmdline.substr(cnctrs.at(cnctrs.size() - 1) + 1);// if right = | then user must enter another command or something
		right.erase(0,1);
		Exit(left);
		Exit(right);		
		if(right == "|")
		{
			right = "";
			cout << "> ";
			getline(cin, right);
		}
		t = new Command(left);
		t2 = new Command(right);
		start = new Or(t, t2);
		//cout << connector << endl;
		//cout << left << endl;
		//cout << right << endl;
	}			
		//cout << "Cnt: " << cnt << endl;
}
//cout << "done with splits" << endl;
};

void Exit(string s)
{
	size_t found = s.find("exit");
	size_t found1 = s.find("Exit");
	if(found != string::npos)
	{
		exit(0);
	}
	if(found1 != string::npos)
	{
		exit(0);
	}
};
	


public:
//	Base* start;	
	Cmd() // Constructors takes data form the command line 
	{
		cout << "$ ";
		getline(cin, cmdline);
		//cout << "start clean up" << endl;
		cleanUp();
	}
	void Execute()
	{
		start->execute();
	}



};

#endif	
