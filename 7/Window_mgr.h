#ifndef WINDOW_MGR
#define WINDOW_MGR
#include <iostream>
#include <vector>
#include "Screen.h"
using namespace std;

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	vector<Screen> screens{ Screen(24,80,' ') };
};

inline void Window_mgr::clear(ScreenIndex i) {
	Screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
};

inline Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}
#endif
