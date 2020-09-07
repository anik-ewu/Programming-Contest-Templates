#include<bits/stdc++.h>
using namespace std;
#define S 10000000
long long int mark[S+7];
int prime[S];
int siv()
{
    int x,y;
    for(x=0; x<S; x++)
        mark[x]=0;
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
int findb(long long int n)
{
    int i,val;
    val=sqrt(n)+1;
    for(i=2; i<val; i++)
        if(n%i==0)
            return 1;
    return 0;
}
int main()
{
    long long int a,b,c,i,j,k,x=0,y,z;
    siv();
    while(cin>>a)
    {
        if(a==0)break;
        b=abs(a);
        cout<<a<<" = ";
        z=findb(b);
        if(z==0 || b==1)
        {
            if(a>1)
                cout<<b<<endl;
            else if(a==1)
                cout<<endl;
            if(b==1 && a<1)
                cout<<a<<" x "<<endl;
            else if(a<1)
                cout<<"-1 x "<<b<<endl;
        }
        else
        {
            y=0;
            if(a<0)
                cout<<"-1 x ";
            for(i=0; i<100000; i++)
                if(b%prime[i]==0)
                {
                    while(b%prime[i]==0)
                    {
                        if(b<prime[i])break;
                        c=b/prime[i];
                        b/=prime[i];
                        y++;
                        if(y>1)
                            cout<<" x ";
                        cout<<prime[i];
                    }
                    if(b<prime[i])break;
                }
            if(b>1)
            {
                cout<<" x ";
                cout<<b;
            }
            cout<<endl;
        }

    }
    return 0;
}

