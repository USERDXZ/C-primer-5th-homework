#include <string>
#include <iostream>
using namespace std;

class getString{
public:
    getString(istream& i = cin):in(i){}
    string operator()(){
        string s;
        if(getline(in,s))
            return s;
        else
            return ""; 
    }
private:
    istream& in;
};