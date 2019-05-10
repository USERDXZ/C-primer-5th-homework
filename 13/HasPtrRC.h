#ifndef HASPTRRC_H
#define HASPTRRC_H
#include <string>
using namespace std;

class HasPtr{
public:
    HasPtr(const string& s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    string* ps;
    int i;
    size_t* use;
}

HasPtr::HasPtr(const HasPtr& ori){ //拷贝构造函数
    ps = ori.ps;
    i = ori.i;
    use = p.use;
    ++*use;
}

HasPtr& HasPtr::operator=(const HasPtr& ori){//拷贝赋值运算符
    if(--*use==0)
    {
        delete ps;
        delete use;
    }
    ps = ori.ps;
    i = ori.i;
    use = p.use;
    ++*use;
    return *this;
}

HasPtr::~HasPtr(){
    if(--*use==0)
    {
        delete ps;
        delete use;
    }
}
#endif