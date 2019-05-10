#include<iostream>
#include "time.h"
using namespace std;

class numbered
{
public:
	int id;
	numbered(){id = rand()%100000;};
	numbered(numbered& a) {
		id = rand()%100000;
	}
	
};

// void f(numbered s) {
// 	cout << s.id << endl;
// }

void f(const numbered& s) {
	cout << s.id <<endl;
}
int main() {
	srand(time(0));
	numbered a, b = a, c = b;
	f(a);f(b);f(c);
 
	return 0;
}
