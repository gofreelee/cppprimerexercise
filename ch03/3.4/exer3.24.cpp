#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> numVec;
    int number;
    while (cin >> number)
    {
        numVec.push_back(number);
    }
    cout<<"*********"<<endl;
    for (auto iter = numVec.begin(); iter != numVec.end() - 1; ++iter)
    {
        cout << *iter + *(iter + 1) << endl;
    }
    cout << "**********" << endl;
    for (auto iter = numVec.begin(),it2 = numVec.end() - 1; iter != numVec.begin() + numVec.size() / 2;++iter,--it2)
    {
        cout << *iter + *it2 << " ";
    }
}