#include<string>
using Type =  std::string;
Type initVal();
class Exercise
{
public:
    using Type = double; // 实际上这样不行
    Type setVal(Type);
    Type initVal();
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm)
{
    val += parm + initVal();
    return val;
}