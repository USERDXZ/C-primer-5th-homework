#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vi = {3,6,9};
	auto r = find_if(vi.begin(),vi.end(),bind(modulus<int>(),54,placeholders::_1));
	if(r == vi.end()) cout << "Yes"<<endl;
	else cout << "No"<<endl;
	return 0;
}
