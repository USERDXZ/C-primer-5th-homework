#include <iostream>

int main() {
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    /*
    size_t cnt=0;
    for(auto &row:ia)
        for(auto &col:row)
        {
            col = cnt;
            ++cnt;
        }    
    for(int (&row)[4]:ia)
        for(int &col:row)
            std::cout<<col<<std::endl; 
            
    for(int i=0;i<end(ia)-begin(ia);++i)
        for(int j=0;j<4;++j)
            std::cout<<ia[i][j]<<std::endl;
    */
    for(int (*p)[4] = ia;p != end(ia);++p)
        for(int *q = *p;q != end(*p);++q)
            std::cout<<*q<<std::endl;
}