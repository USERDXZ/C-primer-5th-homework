#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s("some string");
    if(!s.empty())
    {
        auto it = s.begin();
        *it = toupper(*it);
        std::cout<<s<<std::endl;
    }
    vector<int> vint(10,2);
    for(auto it = vint.begin();it!=vint.end();++it){
        *it = 2**it;
        std::cout<<*it<<std::endl;
    }
    return 0;
}
