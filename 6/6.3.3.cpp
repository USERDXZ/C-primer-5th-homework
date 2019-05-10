#include <iostream>
#include <string>
using namespace std;

/*
string (&funs(string (&p)[10],string (&q)[10],int i))[10]{
    return (i%2==0)? p:q;
}

int main() {
    string a[10] = {"a","b","c","d","e","f","g","h","i","j"};
    string b[10] = {"1","2","3","4","5","6","7","8","9","0"};
    cout<<funs(a,b,1)[5]<<endl;
}

#include <iostream>
#include <string>

auto funs(string (&p)[10],string (&q)[10],int i)->string(&)[10]{
    return (i%2==0)? p:q;
}

int main() {
    string a[10] = {"a","b","c","d","e","f","g","h","i","j"};
    string b[10] = {"1","2","3","4","5","6","7","8","9","0"};
    cout<<funs(a,b,1)[5]<<endl;
}

string s[10];
decltype(s) &funs(string (&p)[10],string (&q)[10],int i){
    return (i%2==0)? p:q;
}

int main() {
    string a[10] = {"a","b","c","d","e","f","g","h","i","j"};
    string b[10] = {"1","2","3","4","5","6","7","8","9","0"};
    cout<<funs(a,b,1)[5]<<endl;
}
*/
using arrS = string[10];
typedef string arrS[10];

arrS &funs(string (&p)[10],string (&q)[10],int i){
    return (i%2==0)? p:q;
}

int main() {
    string a[10] = {"a","b","c","d","e","f","g","h","i","j"};
    string b[10] = {"1","2","3","4","5","6","7","8","9","0"};
    cout<<funs(a,b,1)[5]<<endl;
}
