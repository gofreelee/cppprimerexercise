#include<vector>
#include<iostream>
using namespace std;
int outputVector(vector<int>::iterator begin,vector<int>::iterator end)
{
    if(begin == end)
        return 0;
    cout<< *begin;
    outputVector(begin + 1,end);
}

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8};
    outputVector(vec.begin(),vec.end());
}