#include <iostream>
#include <list>
#include <string>
#include <deque>
using namespace std;

int main()
{
    string s;
    deque<string> ds;//9.19 deque->list
    while(cin>>s)
        ds.emplace_back(s);
    for(auto b = ds.begin();b!=ds.end();++b)
        cout<<" "<<*b;
    cout<<endl;

    list<int> ol{1,2,3,4,5,6,7,8,9};
    deque<int> dq1,dq2;
    for(auto b = ol.begin();b!=ol.end();++b)
    {
        if(*b%2)
            dq1.emplace_back(*b);
        else
            dq2.emplace_back(*b);
    }
}