#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void elimDups(vector<string>&);
void biggies(vector<string>&,vector<string>::size_type);
string make_plural(size_t,const string&,const string&);

int main()
{
    int num1=1;
    auto sumTwoNum = [](const int& num1,const int& num2){return num1+num2;};
    cout<<sumTwoNum(1,2)<<endl;
    auto numAddOne = [num1](const int& num){return num1+num;};
    cout<<numAddOne(5)<<endl;
    vector<string> vs = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    biggies(vs,5);
    return 0;
}

void elimDups(vector<string>& words)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

void biggies(vector<string>& words,vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(),words.end(),
               [](const string& a,const string& b){return a.size()<b.size();});
    auto wc = find_if(words.begin(),words.end(),[sz](const string& a){return a.size()>=sz;});
    //auto end_out = partition(words.begin(),words.end(),[sz](const string& a){return a.size()<sz;});
    //auto end_out = stable_partition(words.begin(),words.end(),[sz](const string& a){return a.size()<sz;});
    auto count = words.end()-wc;
    cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;
    for_each(wc,words.end(),[](const string& s){cout<<s<<" ";});
    cout<<endl;
}

string make_plural(size_t ctr,const string& word,const string& ending)
{
    return (ctr>1)?word+ending:word;
}