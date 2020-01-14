#include<vector>
using namespace std;
int main()
{
    vector<int> e1(10,42);
    vector<int> e2{42,42};//写10个42
    vector<int> e3;
    for(int i = 0; i < 10; i++)
        e3.push_back(42);
}