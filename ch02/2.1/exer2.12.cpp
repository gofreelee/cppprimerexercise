#include<iostream>
using namespace std;
int main()
{
    //int double = 3.33;
    int _;
   // int catch-22;
  //  int 1_or_2;
    double Double = 3.14;
    int i  = 100;
    for(int i = 0;i< 10;i++)
    {}
    std::cout<<i;
    int & ref = i;
    int j = ref;
    double db = 19.9;
    double & dref = db;
    dref = ref;
    ref = db;   
}