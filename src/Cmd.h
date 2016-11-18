#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "tree.h"
using namespace std;



class Cmd 
{
    protected:
        Base* start;
        string cmdline;// Is the string where the command line is stored
        
        void cleanUp()
        { // removes all spaces from the command line and removes everything at and after the # character appears.
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
        
        void split()
        { // splits the cmdline by the connector and commands and orangized which commands go to which connectors not complete yer
            //Base* t;
            //Base* t2;
            //Base* t3;
            //Base* t4;
            vector<int> cnctrs;
            getConnectors(cnctrs);
            makeCommands(cnctrs);
        }
        
        void getConnectors(vector<int>& c) // This function input all of the connector and the parentheses into a vector
        {
            for(unsigned i = 0; i <  cmdline.length(); i++)
            {
                if(cmdline.at(i) == ';' || cmdline.at(i) == '&' || cmdline.at(i) == '|')
                {
                        if(cmdline.at(i) == '&')
                        {
                                c.push_back(i);
                        }
                        else if(cmdline.at(i) == '|')
                        {
                                c.push_back(i);
                        }
                        if(cmdline.at(i) == ';')
                        {
                                c.push_back(i);
                        }
                        if(cmdline.at(i) == '(')
                        {
                                c.push_back(i);
                        }
                        if(cmdline.at(i) == ')')
                        {
                                c.push_back(i);
                        }
                }
            }
        }
        
        void makeCommands(vector<int>& c1)
        {// this function determines if the command line has no, one or multiple operators to execute
            if(c1.size() == 0)
            {
                //      // << "single commands" << endl;
                start = new Command(cmdline);
                //// << "done with singles" << endl;
            }
            else if(c1.size() == 1 || c1.size() == 2)
            {
                // << "one" << endl;
                oneConnector(c1);
            }
            else
            {
                // << "multi" << endl;
                multi(c1);            
            }
        }
        
        
        void oneConnector(vector<int> c2)
        {// this function executes when there is only one connector in the command line
            Base* t = NULL;
            Base* t2 = NULL;
            Base* t3 = NULL;
            Base* t4 = NULL;
            //string temp = cmdline;
            string left = "";
            string right = "";
            string dsemi = "";
            string connector = "";
            if(c2.size() == 1)
            {
                
                if(cmdline.at(c2.at(c2.size() - 1)) == ';')
                {
                    // << "one semi" << endl;
                    connector = "semi";
                    left = cmdline.substr(0, (c2.at(c2.size() - 1)));
                    right = cmdline.substr((c2.at(c2.size() - 1)) + 1);
                    if(right.at(0) == ' ')
                    {
                        right.erase(0,1);
                    }
                    t2 = new Command(right);
                    t = new Command(left);
                    start = new Semi(t, t2);
                
                }
            }
            else
            {
                
                if(cmdline.at(c2.at(c2.size() - 1)) == '&')
                {
                    connector = "and";
                    //// << "AND " << endl;
                                            //// << "size: " << cnctrs.size() << endl;
                    left = cmdline.substr(0,c2.at(0));
                    if(left.at(left.length() - 1) == '&')
                    {
                        left.erase(left.length() - 1);
                    }
                    if(left.at(left.length() - 1) == ' ')
                    {
                        left.erase(left.length() - 1);
                    }
                    // << left << endl;
                    // << c2.at(1) + 1 << endl;
                    // << cmdline.size() << endl;
        
                    // << (c2.at(1) + 1) << endl;
                    right = cmdline.substr(c2.at(c2.size() - 1) + 1); // if right = & then user must enter another command
                    // << right << endl;
                    if(right.at(0) == ' ')
                    {
                        right.erase(0,1);
                    }
                    t2 = new Command(right);
                    t = new Command(left);
                    start = new And(t, t2);
                } // also make sure the both and and or do not remove the last char if they are they only ops with nothing after
                if(cmdline.at(c2.at(c2.size() - 1)) == '|')
                {
                    connector = "or";
                    left = cmdline.substr(0,c2.at(0));
                    if(left.at(left.length() - 1) == '|')
                    {
                        left.erase(left.length() - 1);
                    }
                    if(left.at(left.length() - 1) == ' ')
                    {
                        left.erase(left.length() - 1);
                    }
                    right = cmdline.substr(c2.at(c2.size() - 1) + 1); // if right = & then user must enter another command
                    if(right.at(0) == ' ')
                    {
                        right.erase(0,1);
                    }
                    t2 = new Command(right);
                    t = new Command(left);
                    start = new Or(t, t2);
                    //// << connector << endl;
                    //// << left << endl;
                    //// << right << endl;
                }
                if(cmdline.at(c2.at(c2.size() - 1)) == ';')
                {
                    left = cmdline.substr(0,c2.at(0));
                    if(left.at(left.length() - 1) == ' ')
                    {
                        left.erase(left.length() - 1);
                    }
                    right = cmdline.substr(c2.at(0) + 1, (c2.at(1) - (c2.at(0) + 1)));
                    if(right.at(0) == ' ')
                    {
                        right.erase(0,1);
                    }
                    if(right.at(right.length() - 1) == ' ')
                    {
                        right.erase(right.size() - 1);
                    }
                    //// << "Right: " << right << endl;
                    dsemi = cmdline.substr(c2.at(c2.size() - 1) + 1);
                    if(dsemi.at(0) == ' ')
                    {
                        dsemi.erase(0,1);
                    }
                    t = new Command(left);
                    t2 = new Command(right);
                    t3 = new Semi(t,t2);
                    t4 = new Command(dsemi);
                    start = new Semi(t3,t4);
                }
            }
        }
        
        void multi(vector<int> c3)
        {// this executes where there are multiple connectors and parenthesis
            int count = 0;
            string temp = cmdline;
            string left = "";
            string right = "";
            //string nleft = "";
            string nright = "";
            int T = 0;
            //string connct = "";
            //string connector = "";
            Base* t = NULL;
            Base* t1 = NULL;
            Base* t2 = NULL;
            Base* t3 = NULL;
            Base* t4 = NULL;
            Base* t5 = NULL;
            // << c3.size() - 1 << endl;
            for(unsigned j = 0; j + 1 < c3.size(); j++)
            {
                int result = c3.at(j + 1) - c3.at(j);
                //cout << "J: " << c3.at(j) << ", " << temp.at(c3.at(j)) << endl;
                //cout << "J + 1: " << c3.at(j + 1) << ", " << temp.at(c3.at(j + 1)) << endl;
                //if(j == 0)
                //{

                if(temp.at(c3.at(j)) != temp.at(c3.at(j + 1)))
                {
                    // << "diff" << endl;
                    if(temp.at(c3.at(j)) == ';')
                    {
                        left = temp.substr(0,c3.at(j));
                        // << "a" << endl;
                        if(left.at(left.length() - 1) == ' ')
                        {
                            left.erase(left.length() - 1);
                        }
                        //// << "b" << endl;
                        right = temp.substr(c3.at(j) + 1, ((c3.at(j + 1) - 1) - c3.at(j)));
                        //// << "c" << endl;
                        //// << right << endl;
                        if(right.at(0) == ' ')
                        {
                         //   // << "erase" << endl;
                            right.erase(0,1);
                        }
                        if(right.at(right.length() - 1) == ' ')
                        {
                           // // << "erase1" << endl;
                            right.erase(right.size() - 1);
                            //// << "erase2" << endl;
                        }
                        // << right << endl;
                        if(count == 0)
                        {
                            // << "one" << endl;
                            t = new Command(left);
                            t1 = new Command(right);
                            t2 = new Semi(t,t1);
                            //connect = "Semi";
                            
                            count += 1;
                        }
                        else if(count == 1)
                        {
                            // << "two" << endl; 
                            t3 = new Command(right);
                            t4 = new Semi(t2,t3);
                            //connect = "Semi";
                            
                            count += 1;
                        }
                        else
                        {
                            // << "three" << endl;
                            t5 = new Command(right);
                            t4 = new Semi(t4,t5);
                            count += 1;
                        }
                    }
                    if(temp.at(c3.at(j)) == '&')
                    {
                        left = temp.substr(0,c3.at(j));
                        if(left.at(left.length() - 1) == '&')
                        {
                            left.erase(left.length() - 1);
                        }
                        if(left.at(left.length() - 1) == ' ')
                        {
                            left.erase(left.length() - 1);
                        }
                        // << left << endl;
                        right = temp.substr(c3.at(j) + 1, ((c3.at(j + 1) - 1) - c3.at(j)));
                        if(right.at(0) == ' ')
                        {
                            right.erase(0,1);
                        }
                        if(right.at(right.length() -1) == ' ')
                        {
                            right.erase(right.size() - 1);
                        }
                        // << right << endl;
                        if(count == 0)
                        {
                            //// << "onea" << endl;
                            t = new Command(left);
                            t1 = new Command(right);
                            t2 = new And(t,t1);
                            count += 1;
                            T = (c3.size() - 1) - j;
                            // << T << endl;
                            if(T == 1)
                            {
                                nright = temp.substr(c3.at(j + 1) + 1);
                                t3 = new Command(nright);
                                if(temp.at(c3.at(2)) == ';' )
                                {
                                    t4 = new Semi(t2,t3);
                                    count += 1;
                                }
                                
                            }
                            
                        }
                        else if(count == 1)
                        {
                            // << "twoa" << endl;
                            t3 = new Command(right);
                            t4 = new And(t2,t3);
                            //connect = "And";
                            
                            count += 1;
                        }
                        else
                        {
                            // << "threea" << endl;
                            t5 = new Command(right);
                            t4 = new And(t4,t5);
                            count += 1;
                            
                        }
                    }
                    if(temp.at(c3.at(j)) == '|') 
                    {
                        // << "O"<< endl;
                        left = temp.substr(0,c3.at(j));
                        if(left.at(left.length() - 1) == '|')
                        {
                            left.erase(left.length() - 1);
                        }
                        if(left.at(left.length() - 1) == ' ')
                        {
                            left.erase(left.length() - 1);
                        }
                        right = temp.substr(c3.at(j) + 1, ((c3.at(j + 1) - 1) - c3.at(j)));
                        if(right.at(0) == ' ')
                        {
                            right.erase(0,1);
                        }
                        if(right.at(right.length() - 1) == ' ')
                        {
                            right.erase(right.size() - 1);
                        }
                        if(count == 0)
                        {
                            //// << "oneb" << endl;
                            t = new Command(left);
                            t1 = new Command(right);
                            t2 = new Or(t,t1);
                            //connect = "Or";
                            T = (c3.size() - 1) - j;
                            // << T << endl;
                            if(T == 1)
                            {
                                nright = temp.substr(c3.at(j + 1) + 1);
                                t3 = new Command(nright);
                                if(temp.at(c3.at(2)) == ';' )
                                {
                                    t4 = new Semi(t2,t3);
                                    count += 1;
                                }
                                
                            }
                            
                            count += 1;
                            // << count << endl;
                        }
                        else if(count == 1)
                        {
                            //// << "twob" << endl;
                            t3 = new Command(right);
                            t4 = new Or(t2,t3);
                            //connect = "Or";
                            
                            count += 1;
                        }
                        else
                        {
                            // << "threeb" << endl;
                            t5 = new Command(right);
                            t4 = new Or(t4,t5);
                            count += 1;
                            
                        }
                    }
        
                }
                if(temp.at(c3.at(j)) == ';' && temp.at(c3.at(j + 1)) == ';')
                {
                    left = temp.substr(0,c3.at(j));
                    if(left.at(left.length() - 1) == ' ')
                    {
                        left.erase(left.length() - 1);
                    }
                    right = temp.substr(c3.at(j) + 1, (c3.at(j + 1) - c3.at(j)));
                    if(right.at(0) == ' ')
                    {
                        right.erase(0,1);
                    }
                    if(right.at(right.length() - 1) == ' ')
                    {
                        right.erase(right.size() - 1);
                    }
                    if(count == 0)
                    {
                        //// << "onec" << endl;
                        t = new Command(left);
                        t1 = new Command(right);
                        t2 = new Semi(t,t1);
                        //connect = "Semi";
                        
                        count += 1;
                    }
                    else if(count == 1)
                    {
                        //// << "twoc" << endl;
                        t3 = new Command(right);
                        t4 = new Semi(t2,t3);
                        //connect = "Semi";
                        
                        count += 1;
                    }
                    else
                    {
                        //// << "threec" << endl;
                        t5 = new Command(right);
                        t4 = new Semi(t4,t5);
                        count += 1;
                    }    
                }
                if(temp.at(c3.at(j)) == temp.at(c3.at(j + 1)) && result == 1)
                {
                    //cout << "Pairs" <<endl;
                    //// << "Semi" << endl;
                    if(temp.at(c3.at(j)) == '&' && temp.at(c3.at(j + 1)) == '&')
                    {
                       // << "And" << endl;
                    //    // << "j: " << j << ", " << c3.at(j) << endl;
                     //   // << "j + 1: " << j + 1 << ", " << c3.at(j + 1) << endl;
                        //// << "j + 2: " << j + 2 << ", " << c3.at(j + 2) << endl;
                        left = temp.substr(0,c3.at(j));
                        // << left << endl;
                        if(left.at(left.length() - 1) == '&')
                        {
                            left.erase(left.length() - 1);
                        }
                        if(left.at(left.length() - 1) == ' ')
                        {
                            left.erase(left.length() - 1);
                        }
                        // << "Left: " << left << endl;
                       // // << "M" << endl;
                        if(j + 1 == c3.size() - 1)
                        {
                           // << "Check1 " << endl;
                            right = temp.substr(c3.at(j + 1), temp.size() - c3.at(j + 1));
                        }
                        else
                        {
                            // << "Check2 " << endl;
                            //// << temp.at(c3.at(j + 1) + 2) << endl;
                            if(j + 2 != c3.size() - 1)
                            {
                                // << "special" << endl;
                                right = temp.substr(c3.at(j + 1) + 1, ((c3.at(j + 2) - 1) - c3.at(j + 1)));
                            }
                        }
                        // << "Right: " << right << endl;
                        if(right.at(0) == ' ')
                        {
                            right.erase(0,1);
                        }
                        if(right.at(right.length() - 1) == '&')
                        {
                            right.erase(right.length() - 1);
                        }
                        if(right.at(right.length() - 1) == ' ')
                        {
                            right.erase(right.size() - 1);
                        }
                        // << right << endl;
                        //// << "and" << endl;
                        if(count == 0)
                        {
                          //  // << "oned" << endl;
                            t = new Command(left);
                            t1 = new Command(right);
                            t2 = new And(t,t1);
                            //connect = "And";
                            count += 1;
                        }
                        else if(count == 1)
                        {
                            //// << "twod" << endl;
                            t3 = new Command(right);
                            t4 = new And(t2,t3);
                            //connect = "And";
                            //// << "N" <<endl;
                            count += 1;
                        }
                        else
                        {
                            //// << "threed" << endl;
                            t5 = new Command(right);
                            t4 = new And(t4,t5);
                            count += 1;
                        }
                    }
                    if(temp.at(c3.at(j)) == '|' && temp.at(c3.at(j + 1)) == '|')
                    {
                        // << "Or" << endl;
                        left = temp.substr(0,c3.at(j));
                        if(left.at(left.length() - 1) == '|')
                        {
                            left.erase(left.length() - 1);
                        }
                        if(left.at(left.length() - 1) == ' ')
                        {
                            left.erase(left.length() - 1);
                        }
                        if(j + 1 == c3.size() - 1)
                        {
                            //// << "Check " << endl;
                            right = temp.substr(c3.at(j + 1), temp.size() - c3.at(j + 1));
                        }
                        else
                        {
                            // << "Check4 " << endl;
                            // << temp.at(c3.at(j + 1) + 2) << endl;
                            if(j + 2 != c3.size() - 1)
                            {
                                // << "special" << endl;
                                right = temp.substr(c3.at(j + 1) + 1, ((c3.at(j + 2) - 1) - c3.at(j + 1)));
                            }
                        }
                        if(right.at(0) == ' ')
                        {
                            right.erase(0,1);
                        }
                        if(right.at(right.length() -1) == ' ')
                        {
                            right.erase(right.size() - 1);
                        }
                        if(count == 0)
                        {
                            //// << "onef" <<endl;
                            t = new Command(left);
                            t1 = new Command(right);
                            t2 = new Or(t,t1);
                            //connect = "Or";
                            count += 1;
                        }
                        else if(count == 1)
                        {
                            //// << "twof" <<endl;
                            t3 = new Command(right);
                            t4 = new Or(t2,t3);
                            //connect = "Or";
                            count += 1;
                        }
                        else
                        {
                            //// << "threef" <<endl;
                            t5 = new Command(right);
                            t4 = new Or(t4,t5);
                            count += 1;
                        }
                    }
                    
                }
            }
            int size = c3.size() -1;
            if(count == size)
            {
                // << "end" << endl;
                if(temp.at(c3.at(count)) == temp.at(temp.length() - 1))
                {
                    if(temp.at(c3.at(count)) == '&' || temp.at(c3.at(count)) == '|')
                    {
                            right = "";
                            // << "> ";
                            getline(cin, right); //
                            t5 = new Command(right);
                            if(temp.at(c3.at(count)) == '&')
                            {
                                t4 = new And(t4, t5);
                            }
                            if(temp.at(c3.at(count)) == '|')
                            {
                                t4 = new Or(t4, t5);
                            }
                    }
                }
                else
                {
                    right = temp.substr(c3.at(count) + 1, (temp.size() - c3.at(count)));
                    if(right.at(0) == ' ')
                    {
                        right.erase(0,1);
                    }
                    if(right.at(right.length() - 1) == ' ')
                    {
                        right.erase(right.size() - 1);
                    }
                    
                    // << "Right end: " << right <<endl;
                    t5 = new Command(right);
                    t4 = new Semi(t4, t5);
                }
            }
            // << "count: " << count << endl;            
           start = t4;
           // << endl; 
        }
        
        
    public: 
        //      Base* start;
        Cmd() // Constructors takes data form the command line
        {
                cout << "$ ";
                getline(cin, cmdline);
                //// << "start clean up" << endl;
                cleanUp();
        }
        void Execute()
        {
                start->execute();
        }
};

#endif

  
  
