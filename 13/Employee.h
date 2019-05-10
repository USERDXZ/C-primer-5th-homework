#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee{
public:
    Employee():EmployeeNo(seq++){}
    Employee(const string& s):name(s),EmployeeNo(seq++){}
    Employee(const Employee& ep){name = ep.name;EmployeeNo = seq++;}
    Employee& operator=(const Employee& ep){name = ep.name;return *this;}
    ~Employee(){};
private:
    static int seq;
    string name;
    int EmployeeNo;
};
int Employee::seq = 0;

#endif