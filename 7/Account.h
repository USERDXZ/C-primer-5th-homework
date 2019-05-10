#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account
{
public:
	Account():amount(0.0){}
	Account(const std::string& s,double am):owner(s),amount(am){}
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double iniRate(){ return 0.02; }
};

double Account::interestRate = iniRate();

void Account::rate(double newRate)
{
	interestRate = newRate;
}
#endif