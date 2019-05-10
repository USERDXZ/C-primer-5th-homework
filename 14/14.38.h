#include <string>
using namespace std;

class equals
{
public:
    equals(size_t n):sz(n){}
    bool operator()(const string& s) const { return s.size()==sz; }
private:
    size_t sz;
};