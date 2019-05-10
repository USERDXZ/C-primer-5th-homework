#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print(ostream& os, const vector<T>& vt)
{
    for(auto b = vt.begin(); b != vt.end(); ++b)
        os<<*b<<" ";
    os<<endl;
}

int main()
{
    vector<int> vi= {1,2,3,4,5};
    print(cout, vi);
    return 0;
}