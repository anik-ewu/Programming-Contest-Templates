#include<iostream>
using namespace std;
int backwar_d(int i,int n,int *a)
{
    if(i<=n)
    {



        backwar_d(i+1,n,a);
        cout<<a[i]<<' ';

    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        int a[5];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        backwar_d(1,n,a);
    }
}

