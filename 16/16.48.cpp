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


int main()
{
    int i = 0, *aPtr = &i;
    const char *cp = "hello";
    std::cout << debug_rep( i ) << std::endl;
    std::cout << debug_rep( aPtr ) << std::endl;
    std::cout << debug_rep( cp ) << std::endl;
    return 0;
}