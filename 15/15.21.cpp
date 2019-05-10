#include<iostream>
#include"Figure.h"
using namespace std;
 
int main()
{
    Circle c1( 4 );
    Rectangle r1( 3, 4 );
    cout << "圆周长： " << c1.perimeter() << endl;
    cout << "圆面积： " << c1.area() << endl;
    cout << "矩形周长： " << r1.perimeter() << endl;
    cout << "矩形面积： " << r1.area() << endl;
 
    cout << endl;
 
    Globe g1( 4 );
    Cuboid cu1( 3, 4, 5 );
    cout << "球体表面积： " << g1.superficial_area() << endl;
    cout << "球体体积： " << g1.volume() << endl;
    cout << "长方体表面积： " << cu1.superficial_area() << endl;
    cout << "长方体体积： " << cu1.volume() << endl;
    return 0;
}
