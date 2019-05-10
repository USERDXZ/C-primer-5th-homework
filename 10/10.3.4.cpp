#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s,string::size_type sz)
{
    return s.size()<=sz;
}



int main()
{
    vector<string> vs = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    string::size_type sz = 6;
    cout<<count_if(vs.begin(),vs.end(),bind(check_size,_1,sz))<<endl;
    
    string nh = "nihao";
    vector<int> vi = {1,2,5,7,9};
    auto wc = find_if(vi.begin(),vi.end(),bind(check_size,nh,_1));
    cout<<*wc<<endl;
    return 0;
}