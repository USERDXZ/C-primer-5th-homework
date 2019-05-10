#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <string>
#include <vector>
#include <memory>
using namespace std;

class StrBlobPtr
{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob& a,size_t sz=0):wptr(a.data),curr(sz){}
    string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
private:
    shared_ptr<vector<string>> check(size_t,const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this);}

inline StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size());}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string& msg) const
{
    auto ret= wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i>=ret->size())
        throw out_of_range(msg);
    else
        return ret;
    
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr,"dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr")
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}
#endif