#include<iostream>
 
using namespace std;
 
class X{
public:
    X( int i = 0 ): No( i ) { cout << "X(): " << No << endl; }
    //拷贝构造函数
    X( const X &cpy ) { No = cpy.No; cout << "X( const X& ):" << No << endl; }
    //拷贝赋值运算符
    X& operator=( const X &x ) { No = x.No; cout << "operator=" << endl; return *this; }
    //析构函数
    ~X() { cout << "~X()" << No << endl; }
    unsigned No; //用来表示编号,是public的。
};
 
 
void f1( X x ) { }
void f2( X &x ) { }
 
int main()
{
    {
        X a0;
        cout << endl;
        X a1( 1 );
        cout << endl;
        a0.No = 2;
        X a2( a0 );
        cout << endl;
        a2.No = 3;
        X a3 = a2;
        cout << endl;
        a3 = X(4);//x()->operator= -> ~X()
        cout << endl;
        f1( a0 );
        f2( a0 );
        cout << endl;
    }
    return 0;
}
