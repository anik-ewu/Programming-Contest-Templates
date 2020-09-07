#include<bits/stdc++.h>
using namespace std;
#define S 20000000
int mark[S];
int prime[S];
int prime2[S];

int siv()
{
    long long int x,y,z;

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
        y=x+2;
        if(mark[x]==0 && mark[y]==0)
        {
            prime[z]=x;
            prime2[z]=y;
            z++;
        }
    }
}
int main()
{

    int a,m;
    siv();
    m=0;
    while(m<10001)
    {
        cin>>a;

        cout<<'('<<prime[a]<<", "<<prime2[a]<<')';

        cout<<endl;

        m++;
    }
    return 0;
}

