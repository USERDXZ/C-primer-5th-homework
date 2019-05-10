#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
 
#include<memory>
#include<cstring>
#include<utility>
 
using namespace std;
 
class String{
public:
    //默认构造函数
    String():
        sz(0), p( nullptr ){ }
    //其他构造函数
    String( const char *cp ):
        sz( strlen( cp ) ), p( alloc.allocate( sz ) ) { uninitialized_copy( cp, cp + sz, p ); }
 
    //拷贝构造函数
    String( const String &s ):
        sz( s.sz ), p( alloc.allocate( sz ) ) { cout << "调用了拷贝构造函数" << endl; uninitialized_copy( s.p, s.p + sz, p ); }
    //析构函数
    ~String();
    //移动构造函数
    String( String &&s ) noexcept :
        sz( s.sz ), p( s.p ) { cout << "调用了移动构造函数" << endl; s.sz = 0; s.p = nullptr; }
 
    //移动赋值运算符
    String& operator=( String&& ) noexcept;
 
    //拷贝赋值运算符
    String& operator=( const String & );
    String& operator=( const char *cp );
private:
    //数据成员
    static allocator<char> alloc;
 
    size_t sz;
    char *p;
 
};
 
//静态成员的类外定义
allocator<char> String::alloc;
 
inline
String::~String(){
    if( p )
        alloc.deallocate( p, sz );
}
 
String& String::operator=( const String &s ){
    cout << "调用了拷贝赋值运算符" << endl;
    char *newp = alloc.allocate( s.sz );
    uninitialized_copy( s.p, s.p + sz, newp );
    if( p )
        alloc.deallocate( p, sz );
    sz = s.sz;
    p = newp;
 
    return *this;
}
 
String& String::operator=( const char *cp ){
    cout << "调用了拷贝赋值运算符" << endl;
    auto len = strlen( cp );
    char *newp = alloc.allocate( len );
    uninitialized_copy( cp, cp + len, newp );
    if( p )
        alloc.deallocate( p, sz );
    sz = len;
    p = newp;
 
    return *this;
}
 
String& String::operator=( String &&s ) noexcept {
    cout << "调用了移动赋值运算符" << endl;
    if( this != &s ){
        if( p )
            alloc.deallocate( p, sz );
        p = s.p;
        sz = s.sz;
 
        s.p = nullptr;
        s.sz = 0;
    }
    return *this;
}
 
#endif // STRING_H_INCLUDED