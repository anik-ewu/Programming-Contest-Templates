#include<bits/stdc++.h>
using namespace std;
#define S 10000000
int mark[S+7];
int prime[S];
int siv()
{
    int x,y;
    for(x=4; x<S; x=x+2)
        mark[x]=1;
    for(x=3; x*x<S; x=x+2)
    {
        if(mark[x]==0)
        {
            for(y=x*x; y<S; y=y+x+x)
                mark[y]=1;
        }
    }
    y=0;
    for(x=2; x<S; x++)
    {
        if(mark[x]==0)
            prime[y++]=x;
    }
}
bool check(long long int n)
{
    int i;
    for(i=2; i*i<=n; i++)
        if(n%i==0)
            return true;
    return false;
}
bool check2(long long int n, long long int a[])
{
    siv();
   long long int i,j,x=0,y,z=0,f,t;
    for(j=1; j<n; j++)
    {
        f=0;
        x=0;
        for(i=0; prime[i]*prime[i]<=a[j]; i++)
        {
            if(a[j]%prime[i]==0)
            {
                x++;
                y=a[j]/prime[i];
                if(y!=prime[i])
                    f=1;
            }
        }
        if(f==1)
        {
            if(check(y))
                x++;
        }
        if(x<2 && x!=0)
            z++;
    }
    cout<<z;
}
int main()
{
    long long int a[100000],i,j,k,l,h,m,n,x,y,z,count;
    cin>>n;
    while(n>0)
    {
        x=1;
        cin>>l>>h;
        {
            for(i=l; i<=h; i++)
            {
                if(check(i))
                    a[x++]=i;
            }
            check2(x,a);
            cout<<endl;

            n--;
        }
    }
    return 0;
}





