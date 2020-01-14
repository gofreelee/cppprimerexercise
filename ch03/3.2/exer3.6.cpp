#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s("c++javacscalahadoop");
    for(auto& c : s)
    {
        c = 'X';
    }
    cout<<s;
}