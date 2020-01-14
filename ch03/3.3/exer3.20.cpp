#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> numVec;
    int number;
    while(cin >> number)
    {
        numVec.push_back(number);
    }
    for(int i = 0; i < numVec.size() - 1; i++)
    {
        cout<<numVec[i] + numVec[i+1]<<" ";
    }
    cout<<"**********"<<endl;
    for(int i = 0; i < numVec.size() / 2; i++)
    {
        cout<<numVec[i] + numVec[numVec.size() - 1]<<" ";
    }
}