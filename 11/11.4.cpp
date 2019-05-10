#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string,string> buildMap(ifstream&);
const string& transform(const string&,const unordered_map<string,string>&);
void word_transform(ifstream&,ifstream&);

int main()
{
    return 0;
}

void word_transform(ifstream& map_file,ifstream& input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input,text))
    {
        istringstream stream(text);
        string word;
        while(stream>>word)
            cout<<transform(word,trans_map)<<" ";
    }
    cout<<endl;
}

unordered_map<string,string> buildMap(ifstream& map_file)
{
    unordered_map<string,string> trans_map;
    string key,value;
    while(map_file>>key && getline(map_file,value))
    {
        if(value.size()>1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for "+key);
    }
    return trans_map;
}

const string& transform(const string& s,const unordered_map<string,string>& m)
{
    auto map_it=m.find(s);
    if(map_it!=m.end())
        return map_it->second;
    else
        return s;
}

