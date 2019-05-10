#include <iostream>
#include <string>
using namespace std;
/*8.1.2
istream& readFunc(istream&);

int main() {
	istream& re = readFunc(cin);
}

istream& readFunc(istream& in)
{
	string pr;
	string s;
	while (in >> s) { pr += s; }
	cout << pr << endl;
	in.clear();
	return in;
}
*/
/*8.2.1
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	ifstream input("./test.txt");
	vector<string> out;
	string str;
	while (getline(input,str))
	{
		out.push_back(str);
		cout << str << endl;
	}
}*/

/*8.3.1

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

istream& readFunc(istream&);

int main() {
	istream& re = readFunc(cin);
}

istream& readFunc(istream& in)
{
	string pr;
	string s;
	istringstream read;
	while (getline(in,s))
	{
		read.str(s);
		while(read>>pr)
			cout << pr << endl;
		read.clear();
	}
	in.clear();
	return in;
}*/

