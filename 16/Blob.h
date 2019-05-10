#ifndef BLOB_H
#define BLOB_H
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
using namespace std;

template <typename> class BlobPtr;

template <typename T> class Blob{
    friend class BlobPtr<T>;
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    Blob():data(make_shared<vector<T>>()) {}
    Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)){}
    template <typename It> Blob(It b, It e):data(make_shared<vector<T>>(b, e)){}
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const T& t){data->push_back(t);}
    void push_back(T&& t){data->push_back(std::move(t));}
    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    BlobPtr<T> begin() {return BlobPtr<T>(*this, 0);}
    BlobPtr<T> end() {return BlobPtr<T>(*this, data->size());}
    T& at(size_type);
    const T& at(size_type) const;
    bool operator==(const Blob& a, const Blob& b){return *a.data == *b.data;}
    bool operator!=(const Blob& a, const Blob& b){return !(a == b);}
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string& msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const string& msg) const
{
    if(i >= size())
        throw out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::front()
{
    check(0,"front on empty Blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::front() const
{
    check(0,"front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
    check(0,"back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::at( size_type i ){
    check( i, "subscript out of range" );
    return (*data)[ i ];
}
 
template <typename T>
const T& Blob<T>::at( size_type i ) const{
    check( i, "subscript out of range" );
    return (*data)[ i ];
}

template <typename T> class BlobPtr{
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T>& a, size_t sz=0):wptr(a.data), curr(sz){}
    T& operator*() const{
        auto ret = check(curr, "dereference past end");
        return (*ret)[curr];
    }
    T& operator->() const{
        return & this->operator*();
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

    bool operator==(const BlobPtr& lhs, const BlobPtr& rhs){return lhs.wptr.lock().get() == rhs.wptr.lock().get();}
    bool operator!=(const BlobPtr& lhs, const BlobPtr& rhs){return !(lhs == rhs);}
private:
    shared_ptr<vector<T>> check(size_t, const string&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound BlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    else
        return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtr")
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    auto ret = *this;
    --*this;
    return ret;
}
#endif