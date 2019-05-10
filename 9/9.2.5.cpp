#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main()
{
    list<const char *> old{"a","bb","ccc"};
    vector<string> newv;
    auto index = old.cbegin();
    newv.push_back(*++index);
    cout<<newv[0]<<endl;
    newv[0] = *++index;
    cout<<newv[0]<<endl;
}