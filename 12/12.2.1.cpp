#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char* concat(const char* a, const char* b)
{
    char* p = new char[strlen(a)+strlen(b)]();
    size_t i=0;
    for(;i<strlen(a);++i)
        p[i] = a[i];
    for(size_t j=0;j<=strlen(b);++j)
        p[i+j] = b[j];
    return p;
}

char* sconcat(const string& a, const string& b)
{
    char* p = new char[a.size()+b.size()];
    strcat(p,a.c_str());
    strcat(p,b.c_str());
    return p;
}

int main()
{
    const char* c1 = "cat";
    const char* c2 = "bird";
    auto p1 = concat(c1,c2);
    delete [] p1;
    const string s1 = "cat";
    const string s2 = "bird";
    auto p2 = sconcat(s1,s2);
    delete [] p2;

    
    string s;
    cin >> s;
    char *pc = new char[s.size()]();
    strcat(pc, s.c_str());
    cout << pc << endl;
    delete [] pc;
    return 0;
}