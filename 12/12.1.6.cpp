#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"
#include "StrBlobPtr.h"
using namespace std;

int main()
{
    StrBlob sb;
    string s;
    while(cin>>s)
        sb.push_back(s);
    auto b = sb.begin();
    for(auto n = sb.size();n>0;--n)
    {
        cout<<b.deref()<<" ";
        b.incr();
    }
    cout<<endl;
    return 0;
}