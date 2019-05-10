#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
int search(const vector<T>& vt, T t){
    int times = 0;
    for(auto b:vt){
        if(b == t)
            ++times;
    }
    return times;
}

template <>
int search(const vector<const char*>& vt, const char* t){
    int times = 0;
    for(auto b:vt){
        if(strcmp(b,t)==0)
            ++times;
    }
    return times;
}

int main()
{
    vector<int> iv = {1,1,1,2,2,2,3,3,3,3};
    vector<double> dv = {11.0,12.0,13.0};
    vector<string> sv = {"one", "one", "zero"};
    vector<const char*> cv = {"one", "one", "zero"};
    cout << search(iv, 1) << " ";
    cout << search(dv, 11.0) << " ";
    cout << search(sv, string("one")) << " ";
    cout << search(cv, "one") << endl;
    return 0;
}