#include<iostream>
using namespace std;
#define S 10000000
int mark[S+7];
int prime[S];
int siv()
{
    int x,y;

    mark[0]=1;mark[1]=1;
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
int main()
{
    long long int a,b,c,i,j,k,count,x;
    siv();
    while(cin>>a)
    {
        b=a;
        if(a==0)break;
        count=0;
        for(i=0; prime[i]<=a; i++)
            if(a%prime[i]==0)
        {
            while(a%prime[i]==0)
            {
                a/=prime[i];
            }
            count++;
        }

        cout<<b<<" : "<<count<<endl;
    }
    return 0;
}


