#ifndef VEC_H
#define VEC_H
#include <memory>
#include <initializer_list>
#include <algorithm>
using namespace std;

template <typename T> class Vec{
public:
    Vec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    Vec( initializer_list<T> );
    Vec( const T&, size_t);
    Vec(const Vec&);
    Vec& operator=(const Vec&);
    Vec& operator=( initializer_list<T> );
    Vec(Vec&& sv) noexcept : elements(sv.elements), first_free(sv.first_free), cap(sv.cap){}
    Vec& operator=(Vec&&) noexcept;
    ~Vec();

    bool empty() const { return elements == first_free; }
    size_t size() const { return first_free-elements; };
    size_t capacity() const { return cap-elements; }
    T& operator[](size_t n){ return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }

    void push_back(const T&);
    void push_back(T&&);
    void pop_back();
    T* begin() const { return elements; }
    T* end() const { return first_free; }
private:
    static allocator<T> alloc;
    void chk_n_alloc(){ if(size() == capacity()) reallocate();}
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T* elements;
    T* first_free;
    T* cap;
};

//注意：静态成员的类外定义。
template <typename T> allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::push_back(const T& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::push_back(T&& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

template <typename T>
void Vec<T>::pop_back()
{
    if(!empty())
        alloc.destroy(--first_free);
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e)
{
    auto data = alloc.allocate(e - b);
    return {data,uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
/*
    for_each(elements, first_free, [](const T& s){ alloc.destroy(&s); });
    alloc.deallocate(elements, cap - elements);
*/
    if(elements){
        for(auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec( initializer_list<T> ls)
{
    auto newdata = alloc_n_copy(ls.begin(), ls.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec( const T& s, size_t n)
{
    auto data = alloc.allocate(n);
    elements = data;
    uninitialized_fill_n( data, n, s );
    cap = first_free = elements + n;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& sv) noexcept
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

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=( initializer_list<T> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate( )
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