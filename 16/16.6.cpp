#include <iostream>
using namespace std;

template<typename T, size_t N>
T* begin(const T (&arr)[N])
{
    return &arr;
}

template<typename T, size_t N>
T* end(const T (&arr)[N])
{
    return &arr[N];
}


int main()
{
    int ia[ 5 ] = { 0, 1, 2, 3, 4 };
    auto b = begin( ia );
    auto e = end( ia );
    while( b != e )
        cout << *b++ << " ";
    cout << endl;
    return 0;
}