#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    vector<string> first{"jack Ma","aZhen","aWei"};
    vector<int> second{1,2,3};
    vector<pair<string,int>> sip;
    auto s_iter = second.begin();
    for(auto c:first)
        sip.push_back({c,*s_iter++});//make_pair(c,*s_iter++)
}