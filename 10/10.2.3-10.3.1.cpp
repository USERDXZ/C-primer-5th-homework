#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Sales_data.h"
using namespace std;

void elimDups(vector<string>&);
void outv(vector<string>&);
bool isShorter(const string&,const string&);
bool compareIsbn(const Sales_data&,const Sales_data&);
bool isLongerThanFive(const string&);

int main()
{
    vector<string> vs = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(vs);
    stable_sort(vs.begin(),vs.end(),isShorter);
    outv(vs);
    
    vector<Sales_data> vSd = {Sales_data("book_100"),Sales_data("book_1")};
    sort(vSd.begin(),vSd.end(),compareIsbn);
    //sort(vSd.begin(),vSd.end(),[](const Sales_data& a,const Sales_data& b){return a.isbn()<b.isbn();});

    auto end_out = partition(vs.begin(),vs.end(),isLongerThanFive);
    for(auto b = vs.begin();b!=end_out;++b)
        cout<<*b<<" ";
    cout<<endl;
    return 0;
}

void outv(vector<string>& vs)
{
    for(auto b = vs.cbegin();b!=vs.cend();++b)
        cout<<*b<<" ";
    cout<<endl;
}

void elimDups(vector<string>& words)
{
    sort(words.begin(),words.end());
    outv(words);
    auto end_unique = unique(words.begin(),words.end());
    outv(words);
    words.erase(end_unique,words.end());
    outv(words);
}

bool isShorter(const string& s1,const string& s2)
{
    return s1.size()<s2.size();
}

bool compareIsbn(const Sales_data& sd1,const Sales_data& sd2)
{
    return sd1.isbn()<sd2.isbn();
}

bool isLongerThanFive(const string& s)
{
    return s.size()>4;
}