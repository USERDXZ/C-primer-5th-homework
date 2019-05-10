#ifndef HASPTR_H
#define HASPTR_H
#include <string>
using namespace std;

class HasPtr{
    friend void swap(HasPtr&,HasPtr&);
    friend bool operator<(const HasPtr&,const HasPtr&);
public:
    HasPtr(const string& s = string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr() { delete ps; }
private:
    string* ps;
    int i;
}

HasPtr::HasPtr(const HasPtr& ori){ //拷贝构造函数
    ps = new string(*ori.ps);
    i = ori.i;
}

HasPtr& HasPtr::operator=(const HasPtr& ori){//拷贝赋值运算符
    auto newps = new string(*ori.ps);
    delete ps;
    ps = newps;
    i = ori.i;
    return *this;
}

inline bool operator<(const HasPtr& a, const HasPtr& b){
	return *a.ps < *b.ps;
}

inline void swap(HasPtr& rhs,HasPtr& lhs)
{
    using std::swap;
    swap(rhs.ps,lhs.ps);
    swap(rhs.i,lhs.i);
}
#endif