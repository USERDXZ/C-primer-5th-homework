#include <iostream>
#include <string>
#include "Screen.h"
#include "Window_mgr.h"
using namespace std;

int main()
{
	Screen myScreen(5, 5, 'x');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
}