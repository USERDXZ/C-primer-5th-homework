#include <map>
#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;

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
        if(exclude.find(word)==exclude.end())
            ++word_count[word];
    }
    for(const auto& w:word_count)
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times":" time")<<endl;
    return 0;
}