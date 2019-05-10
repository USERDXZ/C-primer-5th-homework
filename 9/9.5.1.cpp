#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<char> ch = {'h','e','l','l','o'};
    string s(ch.begin(),ch.end());
    cout<<s<<endl;
}