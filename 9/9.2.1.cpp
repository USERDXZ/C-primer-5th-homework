#include <vector>
#include <iostream>
using namespace std;

vector<int>::const_iterator findNum(vector<int> &vi,int num)
{
    vector<int>::const_iterator b;
    for(b=vi.begin();b!=vi.cend();++b)
    {
        if(*b==num) 
            break;
    }
    return b;
}

int main()
{
    vector<int> vi{1,2,3,4,5};
    int num;
    cin>>num;
    if(findNum(vi,num)!=vi.cend())
        cout<<"find it"<<endl;
    else
        cout<<"can't find the num"<<endl;
}