#include <memory>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    allocator<string> alloc;
    size_t n = 5;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while(cin>>s && q!=p+n)
        alloc.construct(q++,s);
    while(q!=p)
    {
        cout<<*--q<<" ";
        alloc.destroy(q);
    }
    alloc.deallocate(p,n);
    return 0;
}