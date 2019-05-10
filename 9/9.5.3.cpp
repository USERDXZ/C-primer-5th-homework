#include <iostream>
#include <string>
using namespace std;

void findFirst(string&s, string& num) {
	int pos = 0;
	while((pos = s.find_first_of(num, pos)) != string::npos) {
		cout << "number index: "<< pos << " is "<< s[pos] <<endl;
		pos++;
	}
	pos = 0;
	while((pos = s.find_first_not_of(num, pos)) != string::npos) {
		cout << "character index: "<< pos << " is "<< s[pos] <<endl;
		pos++;
	}
}
