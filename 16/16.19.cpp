#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print(ostream& os, const vector<T>& vt)
{
    for(typename vector<T>::size_type i = 0;i != vt.size(); ++i)
        os<<vt[i]<<" ";
    os<<endl;
}

int main()
{
    vector<int> vi= {1,2,3,4,5};
    print(cout, vi);
    return 0;
}