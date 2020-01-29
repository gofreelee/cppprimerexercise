#include"Screen.h"
#include<vector>
class WindowMgr
{
private:
    std::vector<Screen> screens = vector<Screen>(4,Screen(1,3,' ')); //列表初始化 ,
public:
    std::vector<Screen> getScreens() const
    {
        return screens;
    }
};