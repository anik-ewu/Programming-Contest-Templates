#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int a[1000],b,c,i,j,k,x,y,z,n;
    cin>>n;
    while(n>0)
    {
        cin>>c;
        y=0;
        x=0;
        for(i=1; i<=c; i++)
        {
            cin>>a[i];
        }
        for(i=1; i<c; i++)
            for(j=i+1; j<=n; j++)
        {
            x=gcd(a[i],a[j]);
            if(y<x)
                y=x;
        }
        cout<<y<<endl;
        n--;
    }
    return 0;
}
