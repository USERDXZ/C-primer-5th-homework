#include <list>
#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
    list<int> vl = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vl.begin();
    while(iter!=vl.end())
    {
        if(*iter%2)
        {
            vl.emplace(iter,*iter);
            ++iter;
        }else
        {
            iter = vl.erase(iter);
        }
    }
    for(auto b = vl.begin();b!=vl.end();++b)
        cout<<" "<<*b;
    cout<<endl;
    forward_list<int> vf = {0,1,2,3,4,5,6,7,8,9};
    auto curr = vf.begin();
    auto prev = vf.before_begin();
    while(curr!=vf.end())
    {
        if(*curr%2)
        {
            prev = vf.insert_after(prev,*curr);
            ++prev;
            ++curr;
        }else
        {
            curr = vf.erase_after(prev);
        }
    }
    for(auto b = vf.begin();b!=vf.end();++b)
        cout<<" "<<*b;
    cout<<endl;
}