#include "Screen.h"
#include <vector>
class WindowMgr
{
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')}; //列表初始化 ,
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
    std::vector<Screen> getScreens() const
    {
        return screens;
    }
};