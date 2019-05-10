#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T, typename I>
T find(T b, T e, const I& v)
{
    while(b != e && *b != v)
        ++b;
    return b;
}

int main()
{
    vector<int> iv = {1, 2, 3, 4};
    vector<string> sv = {"hello", "my", "name", "is", "Cc"};
    auto res1 = find(iv.begin(), iv.end(), 3);
    auto res2 = find(sv.begin(), sv.end(), "is");
    if( res1 == iv.end() )
        cerr << "cant find 3" << endl;
    else
        cout << "successfully found " << *res1 << endl;
    if( res2 == sv.end() )
        cerr << "cant find is";
    else
        cout << "successfully found " << *res2 << endl;
    return 0;
}