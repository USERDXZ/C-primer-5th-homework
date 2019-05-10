#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

void elimDups(list<int>& nums)
{
    nums.sort();
    nums.unique();
}

int main()
{
    list<int> vi = {1,1,2,2,3,4,4,6,1,2,11,8};
    elimDups(vi);
    for_each(vi.begin(), vi.end(),[](int& i){cout<<i<<' ';});
    cout<<endl;
    return 0;
}