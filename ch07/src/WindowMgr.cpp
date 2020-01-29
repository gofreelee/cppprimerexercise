#include "WindowMgr.h"
//友元不具有传递性
void WindowMgr::clear(ScreenIndex index)
{
    Screen &s = screens[index];
    s.contents = std::string(s.width * s.height, ' ');
}

#include "WindowMgr.h"

WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen& screen)
{
    screens.push_back(screen);
    return screens.size() - 1;
}