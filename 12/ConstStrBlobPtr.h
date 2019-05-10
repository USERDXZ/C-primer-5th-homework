#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H
#include <string>
#include <vector>
#include <memory>
using namespace std;

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr(const StrBlob& a,size_t sz=0):wptr(a.data),curr(sz){}
    string& deref() const;
    ConstStrBlobPtr& incr();
    const string& operator*() const;
    const string* operator->() const;
private:
    shared_ptr<vector<string>> check(size_t,const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this);}

inline ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size());}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i,const string& msg) const
{
    auto ret= wptr.lock();
    if(!ret)
        throw runtime_error("unbound ConstStrBlobPtr");
    if(i>=ret->size())
        throw out_of_range(msg);
    else
        return ret;
}

string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr,"dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr,"increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

const string& ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
} 

const string* ConstStrBlobPtr::operator->() const
{
    return & this->operator*();
}
#endif