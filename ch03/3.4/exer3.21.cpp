#include<vector>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string useStr;
    vector<string> strVec;
    while(cin >> useStr)
    {
        strVec.push_back(useStr);
    }
    auto iter = strVec.begin();
    while(iter != strVec.end())
    {
        auto charIter = (*iter).begin();
        while(charIter != (*iter).end())
        {
            *charIter = toupper(*charIter);
            ++charIter;
        }
        cout<< *iter<<endl;
        ++iter;
    }

}