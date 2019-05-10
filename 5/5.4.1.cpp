#include <iostream>
#include <string>
using namespace std;

int main() {
    int nums = 1,maxnums = 1;
    string last,s;
    std::cin>>last;
    while(std::cin>>s)
    {
        if(s == last){
            ++nums;
            if(nums>maxnums)
                maxnums = nums;
        }
        else{
            last = s;
            nums = 1;
        }
    }
    (maxnums>1)? cout<<maxnums<<endl:cout<<"no"<<endl;
}