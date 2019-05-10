#include <iostream>
#include <string>
using namespace std;

template <typename T>
int compare(const T& t1, const T& t2)
{
    if (t1 < t2) return -1;
    if (t2 < t1) return 1;
    return 0;
}

int main()
{
    int x = 5, y = 7;
    string s1 = "english", s2 = "code";
    cout << compare(x, y) << endl;
    cout << compare(s1, s2) << endl;
    return 0;
}