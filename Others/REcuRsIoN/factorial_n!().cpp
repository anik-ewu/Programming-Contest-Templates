#include<iostream>
#include<fstream>
using namespace std;
long long int fact(int n)
{
    //with forward system
    //if(n!=1)
    //{
       // return i*fact(i+1,n-1);
    //}
    //with back ward system
    if(n<2)return 1;
    else return n*fact(n-1);
}
int main()
{
   int a;
   while(cin>>a)
   {
       cout<<fact(a)<<endl;
   }
   return 0;
}

