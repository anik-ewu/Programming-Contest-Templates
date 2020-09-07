#include<bits/stdc++.h>
using namespace std;
#define S 10000000
int mark[S+7];
int prime[S];
int siv()
{
    int x,y;
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
    for(x=2; x<S; x++)
    {
        if(mark[x]==0)
            prime[y++]=x;
    }
}
int main()
{
    siv();
    long long int r,a,b,c,s,i,j,k,x,y,z,n,sum;
    cin>>n;
    while(n>0)
    {
        cin>>a;
        s=++a;
        while(1)
        {
            b=s;
            r=s;
            c=0;
            while(1)
            {
                if(r==0)break;
                c+=r%10;
                r/=10;
            }
            k=sqrt(b);
            sum=0;
            for(i=0; prime[i]<=k; i++)
            {
                if(b%prime[i]==0)
                {
                    while(b%prime[i]==0)
                    {
                        z=prime[i];
                        b/=prime[i];
                        while(1)
                        {
                            if(z==0)break;
                            sum+=z%10;
                            z/=10;
                        }
                    }
                }

            }
            if(sum==0)sum=1;
            if(b>1)
            {
                while(1)
                {
                    if(b==0)break;
                    sum+=b%10;
                    b/=10;
                }
            }
            if(sum==c)
            {
                cout<<s<<endl;
                break;
            }

            s++;
        }
        n--;
    }
    return 0;
}
