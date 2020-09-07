#include<bits/stdc++.h>
using namespace std;
#define S 10000000
int mark[S+7];
int prime[S+7];
int digit(int n)
{
    int i,x=0;
    while(1)
    {
        if(n==0)break;
        x+=n%10;
        n/=10;
    }
    return x;
}
int siv()
{
    int x,y,z,a,b,c;

    mark[0]=1;
    mark[1]=1;
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
    z=0,c=0;
    for(x=0; x<=S; x++)
    {
        if(mark[x]==0)
        {
            z=digit(x);
            if(mark[z]==0)
                c++;
        }
        prime[y++]=c;
    }
}
int main()
{
    int n,a,b,c,i,j,x,count;
    siv();
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d%d",&a,&b);
        x=prime[b]-prime[a-1];
        cout<<x<<endl;
        n--;
    }
    return 0;
}
