#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include<initializer_list>
using namespace std;

class StrVec{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec( initializer_list<string> );
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec& operator=( initializer_list<string> );
    string& operator[](size_t n){ return elements[n]; }
    const string& operator[](size_t n) const { return elements[n]; }
    ~StrVec();
    StrVec(StrVec&& sv) noexcept : elements(sv.elements), first_free(sv.first_free), cap(sv.cap){}
    StrVec& operator=(StrVec&& sv) noexcept;
    void push_back(const string&);
    size_t size() const { return first_free-elements; };
    size_t capacity() const { return cap-elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
private:
    static allocator<string> alloc;
    void chk_n_alloc(){ if(size() == capacity()) reallocate();}
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string* elements;
    string* first_free;
    string* cap;
};

//注意：静态成员的类外定义。
allocator<string> StrVec::alloc;

void StrVec::push_back(const string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data = alloc.allocate(e - b);
    return {data,uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    //for_each(elements, first_free, [](const string& s){ alloc.destroy(&s); });
    //alloc.deallocate(elements, cap - elements);
    if(elements){
        for(auto p = first_free; p != elements;)
            alloc.destory(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec( initializer_list<string> ls)
{
    auto newdata = alloc_n_copy(ls.begin(), ls.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(StrVec&& sv) noexcept
{
    if(this != sv){
        free();
        elements = sv.elements;
        first_free = sv.first_free;
        cap = sv.cap;
        sv.elements = sv.first_free = sv.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec& s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=( initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate( )
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
#endif