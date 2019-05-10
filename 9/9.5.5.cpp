#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sumString(vector<string> &s)
{
    int sum;
    for(auto b = s.begin();b!=s.end();++b)
    {
        int num = stoi(*b);
        sum+=num;
    }

    return sum;
}

int main()
{
    vector<string> s = {"555","666","777"};
    cout<<sumString(s)<<endl;
    return 0;
}