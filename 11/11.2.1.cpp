#include <map>
#include <string>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    map<string,vector<string>> family;
    string line,name,member;
    while(getline(cin,line))
    {
        istringstream record(line);
        record>>name>>member;
        family[name].push_back(member);
    }
    for(auto &x:family)
        cout << "family "<< x.first << " has "<<x.second.size()<<" persons"<<endl;
    return 0;
}

/*11.8
void last() {
	vector<string> v = {"hello", "hello", "world"};
	set<string> s(v.begin(), v.end());
	sort(v.begin(), v.end());
	auto unique_end = unique(v.begin(), v.end());
	v.erase(unique_end, v.end());
	for(auto x : v)
		cout << "vector: "<< x<<endl;
	for(auto x : s)
		cout << "set: " << x << endl;
	return 0;
}
*/
