#include <iostream>
using namespace std;

template<typename T, size_t N>
constexpr size_t size(const T (&arr)[N])
{
    return N;
}

int main()
{
    int ia[5] = {1,};
    cout << size(ia);
    return 0;
}