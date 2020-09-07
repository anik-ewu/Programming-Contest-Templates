#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[2000050];
int main()
{
    int n,i,j,b,c,d,e,f;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }

        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+0,a+n);

        for(i=0; i<n; i++)
        {
            cout<<a[i]<<' ';
        }
    }
    return 0;
}
