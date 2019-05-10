#include <iostream>

int main() {
    int aa[] = {0,1,2,3,4,5};
    int ab[] = {0,1,2,3,4,6};
    int *a = aa;
    int *b = ab;
    int *e = &aa[6];
    while(a<e){
        if(*a != *b)
        {
            std::cout<<"no"<<std::endl;
            return 0;
        }
        ++a;++b;
    }
    std::cout<<"yes"<<std::endl;
    return 0;
}


/*
#include <iostream>
#include <vector>

int main() {
    vector<int> aa = {0,1,2,3,4,5};
    vector<int> ab = {0,1,3,3,4,5};
    if(aa != ab)
        std::cout<<"no"<<std::endl;
    else
        std::cout<<"yes"<<std::endl;
    return 0;
}
*/