#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    cout<<accumulate(vi.begin(),vi.end(),0)<<endl;

    vector<double> vd = {1.5,3.0,4.0};
    cout<<accumulate(vd.begin(),vd.end(),0)<<endl;
    return 0;
}