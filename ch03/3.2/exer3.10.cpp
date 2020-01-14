#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s;
    cout << "enter string:";
    cin >> s;
    cout << " :";
    string::size_type size = s.size(), iterIndex = 0, useIndex;
    while (iterIndex < size)
    {
        if (ispunct(s[iterIndex]))
        {
            for (useIndex = iterIndex; useIndex < size - 1; ++useIndex)
            {
                s[useIndex] = s[useIndex + 1];
            }
            s[size - 1] = '\0';
            --size;
        }
        else
            ++iterIndex;
    }
    cout<<s;
}