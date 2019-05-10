#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    vector<int> vi= {1,2,3,4,5,0,6,7};
    for(auto rb = vi.crbegin();rb!=vi.crend();++rb)
        cout<<*rb<<" ";
    cout<<endl;
    for(auto b = vi.end();b!=vi.begin();)
        cout<<*--b<<" ";
    cout<<endl;
    auto last = find(vi.crbegin(),vi.crend(),0);
    cout<<*last<<endl;
    list<int> rvi(vi.crbegin()+3,vi.crbegin()+7);
    return 0;
}