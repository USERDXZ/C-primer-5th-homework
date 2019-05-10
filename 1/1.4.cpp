#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int i = 50;
    while (i<=100)
    {
        sum += i;
        ++i;
    }
    std::cout<<sum<<std::endl;
    int x=0,y=0;
    std::cout<<"please enter 2 nums(1<2):"<<std::endl;
    std::cin>>x>>y;
    if (x>y)
    {
        int tmp = y;y = x;x = tmp;
    }
    while (x<y-1)
    {
        ++x;
        std::cout<<x<<std::endl;
    }
    return 0;
}