#include <iostream>
using namespace std;

template<typename T, size_t N>
void print(const T (&arr)[N])
{
    for(auto elem : arr)
        cout<<elem<<endl;
}

int main()
{
    int x[10] = {0,1,2,3,4,5,6,7,8,9};
    int y[5] = {1,2,3};
    print(x);
    print(y);
    return 0;
}