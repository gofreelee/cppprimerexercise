#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s("c++javacscalahadoop");
   string::size_type size = s.size(), iterIndex = 0;
   while(iterIndex < size)
   {
       s[iterIndex++] = 'X';
       //++iterIndex;
   }
   cout<<s;
}