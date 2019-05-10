#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void flst_insert(forward_list<string> &flst,string be,string af)
{
    auto b = flst.begin();
    while(b!=flst.end())
    {
        if(*b==be)
        {
            flst.insert_after(b,af);
            break;
        }
        ++b;
    }
}

int main()
{
    forward_list<string> flst{"first","second","fourth"};
    flst_insert(flst,"second","third");
    for(auto b = flst.begin();b!=flst.end();++b)
        cout<<" "<<*b;
    cout<<endl;
}