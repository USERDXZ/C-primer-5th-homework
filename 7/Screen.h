#include <iostream>
#include <string>
using namespace std;

class Screen
{	
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd):height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}
	friend class Window_mgr;//friend void Window_mgr::clear(ScreenIndex);
	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(ostream& os) { do_display(os); return *this; }
	const Screen& display(ostream& os) const { do_display(os); return *this; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream& os) const { os << contents; }
};

inline char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];
}

inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

inline Screen& Screen::set(pos row, pos col, char ch)
{
	contents[row * width + col] = ch;
	return *this;
}

