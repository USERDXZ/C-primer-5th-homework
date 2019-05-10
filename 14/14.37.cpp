#include <iostream>
#include <vector>
using namespace std;

class equals
{
public:
    equals(int v):v(v){}
    bool operator()(int& a){ return v == a; }
private:
    int v;
};

int main()
{
    vector<int> vi= {1,2,3,4,5,6,7,8,9};
    equals v5(5);
    for(auto i:vi)
    {
        if(v5(i))
            i = 0;
    }
    return 0;
}