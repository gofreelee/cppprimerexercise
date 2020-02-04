#include <iostream>
class Point
{
public:
    Point() = default;
    Point(const Point &res) : elem(res.elem)
    {
        std::cout << "构造函数" << std::endl;
    }

private:
    int elem;
};

Point global;
Point fooBar(Point arg)
{
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap};
    return *heap;
}

int main()
{
    Point t = fooBar(global);
}