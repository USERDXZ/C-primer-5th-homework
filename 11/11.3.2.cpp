#include <map>
#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;

/*
int main()
{
    map<string,size_t> word_count;
    set<string> exclude = {"the","but","and","or","an","a"};
    string word;
    while(cin>>word)
    {
        if(ispunct(word.back()))//ispunct:检查标点符号 .back返回最末尾一个元素
			word = word.substr(0,word.size()-1);
        transform(word.begin(),word.end(),word.begin(),::tolower);  
        auto ret = word_count.insert({word,1});
        if(!ret.second)
            ++ret.first->second;
    }
    for(const auto& w:word_count)
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times":" time")<<endl;
    return 0;
}
*/

int main()
{
    map<string,vector<int>> msvi = {{"jack ma",{1,2,3}}};
    pair<map<string,vector<int>>::iterator,bool> ret = msvi.insert(pair<string,vector<int>>("nine",{9,6}));
    return 0;
}