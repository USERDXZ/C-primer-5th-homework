#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    multimap<string,string> msvs;
    string author = "jack ma";
    auto ret = msvs.find(author);
    if(ret!=msvs.end())
        msvs.erase(ret);
    for(auto iter=msvs.begin();iter!=msvs.end();++iter)
        cout <<iter->first << " "<< iter->second<<endl;
    return 0;
}