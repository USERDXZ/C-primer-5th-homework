#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vi= {1,3,3,3,5,5,5,5,5,7,9};
    cout<<count(vi.begin(),vi.end(),3)<<endl;

    string s;
    list<string> str;
    while(cin>>s)
        str.emplace_back(s);
    cout<<count(str.begin(),str.end(),"me")<<endl;
    return 0;
}
