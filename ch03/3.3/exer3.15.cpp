#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string useStr;
    vector<string> strVec;
    while(cin >> useStr)
    {
        strVec.push_back(useStr);
    }
    for(int i = 0; i < strVec.size(); i++)
    {
        cout<<strVec[i]<<" ";
    }
}