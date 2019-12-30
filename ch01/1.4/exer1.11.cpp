#include<iostream>
using namespace std;
int main()
{
    int left, right;
    std::cout<<"please enter two number:"<<std::endl;
    std::cin>>left>>right;
    int tmp = left;
    left = left > right ? left : right;
    right = tmp > right ? right : tmp;
    int index = right;
    while(index <= left)
    {
        std::cout<<index<<std::endl;
        ++index;
    } 
}