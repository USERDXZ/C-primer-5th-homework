#include <new>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/*
vector<int>* load(istream&);
void out(ostream&,vector<int>*);
vector<int>* create();

int main()
{
    vector<int>* p = load(cin);
    out(cout,p);
    delete(p);
    return 0;
}

vector<int>* create()
{
    return new vector<int>;
}

vector<int>* load(istream& is)
{
    vector<int>* p = create();
    int i;
    while(is>>i)
        p->push_back(i);
    return p;
}

void out(ostream& os,vector<int>* vi)
{
    for(const auto& i:*vi)
        os<<i<<" ";
    os<<endl;
}
*/

shared_ptr<vector<int>> create()
{
    return make_shared<vector<int>>();
}

void load(shared_ptr<vector<int>>& vi)
{
    int k;
    while(cin>>k)
        vi->push_back(k);
}

void out(shared_ptr<vector<int>>& vi)
{
    for(const auto i:*vi)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    shared_ptr<vector<int>> vi = create();
    load(vi);
    out(vi);
    return 0;
}