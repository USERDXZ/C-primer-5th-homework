#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

void readIntTwoFile(const string f1,const string f2,const string f3)
{
    ifstream in_f(f1);
    ofstream ou_f1(f2),ou_f2(f3);
    istream_iterator<int> in_iter(in_f),eof;
    ostream_iterator<int> ou_iter1(ou_f1," "),ou_iter2(ou_f2," ");
    int tmp;
    while(in_iter != eof)
    {
        tmp = *in_iter++;
        if(tmp%2)
            ou_iter1 = tmp;
        else
            ou_iter2 = tmp;
    }
    return 0;
}

int main()
{
    /*
    istream_iterator<string> str_iter(cin),eof;
    vector<string> vs(str_iter,eof);
    for(auto &s:vs)
        cout<<s<<" ";
    cout<<endl;
    */
    istream_iterator<int> in_iter(cin),eof;
    ostream_iterator<int> ou_inter(cout," ");
    vector<int> vi(in_iter,eof);
    sort(vi.begin(),vi.end());
    unique_copy(vi.begin(),vi.end(),ou_inter);
    cout<<endl;
    return 0;
}

/*
bool compareIsb(Sales_item& a, Sales_item& b) {
	return a.isbn() < b.isbn();
}
int main() 
{
	ifstream in_f("book_sales");
	istream_iterator<Sales_item> in_iter(in_f), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");
    if(in_f) {
    	vector<Sales_item> v(in_iter, eof);
    	sort(v.begin(), v.end(),compareIsb);
    	copy(v.begin(), v.end(),out_iter);
    	cout << endl;
    	for(auto begin = v.begin(); begin != v.end();) {
    		auto end = find_if(begin, v.end(), [begin](Sales_item& s) {return s.isbn() != begin->isbn();});
    		Sales_item total(begin->isbn());
    		out_iter = accumulate(begin, end, total);
    		begin = end;
    	}
    }else
        cout << "could not open data."<<endl;
 
    return 0;
}
*/