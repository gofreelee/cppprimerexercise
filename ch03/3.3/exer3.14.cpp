#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int useNum;
    vector<int> numVec;
    while(cin >> useNum)
    {
        numVec.push_back(useNum);
    }
    for(int i = 0; i < numVec.size(); i++)
    {
        cout<<numVec[i]<<" ";
    }
}