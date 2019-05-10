#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

int main() {
	map<string, list<int>> mp;
	string word;
	int line;
	while(cin>>word>>line) {
		mp[word].push_back(line);
	}
	for(auto x : mp) {
		cout <<  "word "<< x.first << " appears in ";
		for_each(x.second.begin(), x.second.end(), [](int&a){cout << "line: "<<a<<' ';});
	    cout << endl;
    //multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)> bookStore(compareIsbn);
    return 0;
	}
}