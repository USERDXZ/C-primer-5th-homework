#include <iostream>
#include <string>
using namespace std;

string concatName(string name,string fwname,string backname)
{
    name.insert(0,fwname,0,fwname.size());
    name.insert(name.size(),backname,0,backname.size());
    return name;
}

void replaceString(string &s,string oldval,string newval)
{
    string inds;
    auto leno = oldval.size();
    for(int b = 0;b<s.size()-leno+1;++b)
    {
        inds = s.substr(b,b+leno);
        if(inds==oldval)
        {
            s.replace(b,b+leno,newval);
            b = b+newval.size()-1;
        }
    }
}

int main()
{ 
    string s = "thoxxxtho";
    replaceString(s,"tho","though");
    cout<<s<<endl;
    cout<<concatName("dd","Mr","Jr.")<<endl;
    return 0;
}