#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


void printInts(list<int>& v) {
	for_each(v.begin(), v.end(), [](int& x){cout << x << ' ';});
	cout << endl;
}

int main()
{
    vector<int> vi={1,1,2,2,3,4,4};
    list<int> li;
    unique_copy(vi.begin(),vi.end(),back_inserter(li));

	vector<int> v = {1,2,3,4,5,6,7,8,9};
	list<int> v1,v2,v3;
	copy(v.begin(), v.end(), inserter(v1,v1.begin()));
	copy(v.begin(), v.end(), back_inserter(v2));
	copy(v.begin(), v.end(), front_inserter(v3));
    printInts(v1);
    printInts(v2);
    printInts(v3);
	return 0;
}