#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    map<int,int> ii={{1,1},{2,2}};
    ii.begin()->second = 3;
    //map<string,size_t>::const_iterator map_it = word_count.cbegin();
    //multimap<Sales_data,bool(*)(const Sales_data&,const Sales_data&)>::iterator map_it = bookstore.begin();
}