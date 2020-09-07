#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,x,y,z,t;
    char a[1000][15];
    cin>>n;
    while(n>0)
    {
        cin>>t;
        for(i=1; i<=t+1; i++)
            cin>>a[i];

        for(i=1; i<=t+1; i++)
        {
            x=int(a[i]);
            cout<<x<<' ';
        }
        n--;
    }
}
