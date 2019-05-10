#include <iostream>

void chang(const int *&p,const int *&q)
{
    const int *tmp = q;
    q = p;
    p = tmp;
}

int main() {
    const int x=1,y=2;
    const int *m = &x,*n=&y;
    chang(m,n);
    std::cout<<*m<<" "<<*n<<std::endl;//6.22 函数交换两个int指针
    return 0;
}