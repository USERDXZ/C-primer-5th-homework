#include <iostream>
#include <string>
using namespace std;

struct Person
{
	friend ostream& print(ostream&, const Person&);
	friend istream& read(istream&, Person&);
public:
	Person() = default;
	Person(const string &s1, const string &s2) :name(s1), address(s2) {}
	Person(istream&is) :Person() { read(is, *this); }
	string gtName() const { return name; }
	string gtAddress() const { return address; }
private:
	string name;
	string address;
};

ostream& print(ostream& os, const Person& p)
{
	os << p.gtName() << " " << p.gtAddress();
	return os;
}

istream& read(istream& is, Person& p)
{
	is >> p.name >> p.address;
	return is;
}