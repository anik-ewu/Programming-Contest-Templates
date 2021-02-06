#include<iostream>
using namespace std;
int sum(int n)
{
    if(n==0)
        return 0;
    else
        return n+sum(n-1);
}
int main()
{
    int a;
    while(cin>>a)
    {
    cout<<sum(a)<<endl;
    }
    return 0;
}
