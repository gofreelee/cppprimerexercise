#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> scores(11,0);
    auto iter = scores.begin();
    int grade;
    while(cin >> grade)
    {
        if(grade <= 100)
        {
            ++*(iter + grade / 10);
        }
    }
    while(iter != scores.end())
    {
        cout<<*iter<<endl;
        iter++;
    }
}