#include<vector>
#include<iostream>
using namespace std;
int main()
{
    using fourEleArray = int[4];
    int ia[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(fourEleArray* ptr = ia; ptr != ia + 3; ++ptr)
    {
        for(int* p = ptr[0]; p != *ptr + 4; p++)
        {
            cout<<*p<<endl;
        }
    }
}