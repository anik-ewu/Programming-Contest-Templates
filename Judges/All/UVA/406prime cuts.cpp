#include<iostream>
using namespace std;
#define S 10000000
int mark[S+7];
int prime[S];
int siv()
{
    int x,y;

    mark[0]=1;
    mark[1]=1;
    for(x=0; x<S; x++)
        mark[x]=0;
    for(x=4; x<S; x+=2)
        mark[x]=1;
    for(x=3; x*x<S; x+=2)
    {
        if(mark[x]==0)
        {
            for(y=x*x; y<S; y+=x+x)
                mark[y]=1;
        }
    }
    y=0;
    for(x=1; x<S; x++)
    {
        if(mark[x]==0)
            prime[y++]=x;
    }
}
int main()
{
    siv();
    int pr[100000],i,j,k,x,y,z,a,b,c;
    while(cin>>a)
    {
        for(i=0; prime[i]<=a; i++)
        {
            pr[i]=prime[i];
            cout<<pr[i]<<' ';
        }
        cout<<i<<endl;
    }
}
