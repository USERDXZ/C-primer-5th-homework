#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"
using namespace std;

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout<<"enter word to look for, or q to quil:";
        string s;
        if(!(cin>>s)||s=="q") break;
        print(cout,tq.query(s))<<endl;
    }
}

int main(int argc, char *argv[])//为啥跑起来不对啊
{
    ifstream file("test.txt");
    runQueries(file);
    return 0;
}