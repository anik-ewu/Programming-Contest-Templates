#include<bits/stdc++.h>
using namespace std;
#define S 1000005
int mark[S];
int prime[S];

int siv()
{
    int i,j,k,l,m,x,y;
    mark[1]=1;
    mark[0]=1;
    for(x=4; x<S; x=x+2)
        mark[x]=1;
    for(x=3; x*x<S; x=x+2)
    {
        if(mark[x]==0)
        {
            for(j=x*x; j<S; j=j+x+x)
                mark[j]=1;
        }
    }
    y=1;
    for(x=2; x<S; x++)
        if(mark[x]==0)
            prime[y++]=x;
}
int main()
{
    int i,j,k,n,a,b,y,arry;
    siv();
    while(cin>>n)
    {
        if(n==0)break;
        y=1;
        k=0;
        while(1)
        {
            a=prime[y];
            b=n-a;
            if(mark[b]==0)
            {

                k++;
            }
            y++;
            if(prime[y]>n)
            {
                break;
            }
        }
        if(k%2!=0)
        {
            k++;
        }
        k=k/2;
        cout<<k<<endl;
    }
    return 0;
}
