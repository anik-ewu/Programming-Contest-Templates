#include<bits/stdc++.h>
using namespace std;
#define S 1000000
int mark[S+7];
int prime[S];
int siv()
{
    int x,y,z;
    mark[1]=1;
    //mark[2]=1;
    mark[0]=1;
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
    z=1;
    for(x=2; x<S; x++)
    {
        if(mark[x]==0)
            prime[z++]=x;
    }
}
int main()
{

    int a,b,c,i,n,j,k,l,m;
    siv();
    k=0;
    while(cin>>n)
    {
        c=2;
        if(n==0)
        {
            break;
        }
        while(1)
        {
            a=prime[c];
            b=n-a;
            if(mark[b]==0)
            {
                cout<<n<<" = "<<a<<" + "<<b<<endl;
                k=1;
                break;

            }
            c++;
        }
    }
    return 0;
}
