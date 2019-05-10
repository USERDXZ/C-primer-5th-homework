#include <iostream>
#include <string>
using namespace std;

template <unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W> ostream& operator<<(ostream&, Screen<H, W>&);
template <unsigned H, unsigned W> istream& operator>>(istream&, Screen<H, W>&);

template <unsigned H, unsigned W> class Screen
{
    friend ostream& operator<< <H, W>(ostream&, Screen<H, W>&);
    friend istream& operator>> <H, W>(istream&, Screen<H, W>&);
public:
    using pos = string::size_type;
    Screen(char c = ' '):cursor(0), contents(H * W, c){}
    char get() const { return contents[cursor];}
    char get(pos ht, pos wd) const 
         { pos row = ht * W; return contents[row + wd];}
    Screen& move(pos r, pos c)
         { pos row = r * W; cursor = row + c; return *this;}
    Screen& set(char ch)
         {contents[cursor] = ch; return *this;}
    Screen& set(pos row, pos col, char ch)
         {contents[row * W + col] = ch; return *this;}
    Screen& display(ostream& os) {do_display(os); return *this;}
    const Screen& display(ostream& os) const {do_display(os); return *this;}
private:
    pos cursor;
    string contents;
    void do_display(ostream& os) const { os << contents;}
};

template <unsigned H, unsigned W> 
ostream& operator<<(ostream& os, Screen<H, W>& scr)
{
    scr.do_display(os);
    return os;
}

template <unsigned H, unsigned W> 
istream& operator>>(istream& is, Screen<H, W>& scr)
{
    string s;
    is >> s;
    scr.contents = s.substr(0, H * W);
    return is;
}