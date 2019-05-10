#include <string>
#include <iostream>
using namespace std;

template <typename T>
ostream& print(ostream& os, const T& t)
{
    return os << t;
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
    cout << t << ",";
    return print(os, rest...);
}

int main()
{
    print(cout, "a", "b", "c", "duck", 42);
    return 0;
}