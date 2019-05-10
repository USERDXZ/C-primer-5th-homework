#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template <typename T> string debug_rep(const T& t)
{
    ostringstream ret;
    ret<<t;
    return ret.str();
}

template <typename T> string debug_rep(T* p)
{
    ostringstream ret;
    ret << "pointer: " << p;
    if(p)
        ret << " " << debug_rep(*p);
    else
        ret << " nullptr ";
    return ret.str();
}

string debug_rep(const string& s)
{
    return '"' + s + '"';
}

string debug_rep(char* p)
{
    return debug_rep(string(p));
}

string debug_rep(const char* p)
{
    return debug_rep(string(p));
}

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

template <typename... Args>
ostream& errorMsg(ostream& os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    int i = 6, *aPtr = &i;
    const char *cp = "Mr.";
    std::string str = "tree";
    errorMsg(std::cerr, aPtr, "hello", cp, str);
    return 0;
}

