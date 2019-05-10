#ifndef STRBLOB_h
#define STRBLOB_h
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    using size_type = vector<string>::size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const string& t){data->push_back(t);}
    void push_back(string&& t){data->push_back(std::move(t));}
    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin();
    ConstStrBlobPtr cend();
    StrBlob(const StrBlob&);
    StrBlob& operator=(const StrBlob&);
    bool operator==(const StrBlob& a, const StrBlob& b){return a.data==b.data;}
    bool operator!=(const StrBlob& a, const StrBlob& b){return !(a==b);}
private:
    shared_ptr<vector<string>> data;
    void check(size_type i,const string& msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){}

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}

void StrBlob::check(size_type i,const string& msg) const
{
    if(i>=data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

string& StrBlob::front() const
{
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

StrBlob::StrBlob(const StrBlob& sb)
{
    data = make_shared<vector<string>>(*sb.data);
}

StrBlob::StrBlob& StrBlob::operator=(const StrBlob& sb)
{
    data = make_shared<vector<string>>(*sb.data);
    return *this;
}
#endif