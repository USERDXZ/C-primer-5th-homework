#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> vs = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    string::size_type sz = 6;
    cout<<count_if(vs.begin(),vs.end(),[&sz](const string& a){return a.size()>=sz;})<<endl;
    int num=6;
    auto f = [&]()->bool{if(num>0) return (num--)==0;else return true;};
    while(!f())
        cout<<"num>0 ";
    cout<<"num=0"<<endl;
    return 0;
}