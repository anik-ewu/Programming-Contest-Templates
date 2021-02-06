#include<iostream>
using namespace std;
long long int arry[100];

long long int fibonaci(int n)
{
    if(n==0 || n==1)
        return 1;
    else if(arry[n]==0)
        arry[n]=fibonaci(n-1)+fibonaci(n-2);
    return arry[n];
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<fibonaci(n)<<endl;
    }
}

