#include <iostream>
#include <utility>
using namespace std;

template <typename F, typename T1, typename T2>
void filp(F f, T1&& t1, T2&& t2){ 
    f(forward<T2>(t2), forward<T1>(t1)); //t1 : int& , t2 : int 
}

void g(int&& i, int& j)
{
    cout << i << " " << j <<endl;
}

int main()
{
    int i = 0;
    filp(g, i, 42);
    return 0;
}