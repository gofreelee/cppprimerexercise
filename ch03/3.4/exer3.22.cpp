#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int>  vec(10,42);
    for(auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        *iter  = *iter * 2;
        cout<< *iter<<endl;
    }

}