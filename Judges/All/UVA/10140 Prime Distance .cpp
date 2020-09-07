#include<bits/stdc++.h>
using namespace std;
#define S 10000000
bool mark[S+7];
vector< long long int >prime,segment,primeans;
void seive()
{
    long long int i,j;
    for( i=4; i<S; i+=2)
        mark[i]=1;
    for(i=3; i*i<=S; i+=2)
    {
        if(mark[i]==0)
        {
            for(j=i*i; j<S; j+=i+i)
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3; i<S; i+=2)
    {
        if(mark[i]==0)
        {
            prime.push_back(i);
        }
    }
}

int segment_seive(long long int l, long long int u)
{
    long long int root,start,si,i,j,count=0;
    root=sqrt(u)+1;
    segment.clear();
    for(i=l; i<=u; i++)
        segment.push_back(i);
    segment.push_back(0);

    for(i=0; prime[i]<=root; i++)
    {
        si=prime[i];
        start=si*si;
        if(start<l)
        {
            start=((l+si-1)/si)*si;
        }
        for(j=start; j<=u; j+=si)
        {
            if(j-l<segment.size())
            {

                if(segment[j-l]!=0)
                {
                    segment[j-l]=0;
                }
            }
        }
    }
    return 0;
}

int main()
{
    seive();
    long long int a,b,c,l,u,n,i,j,k,count;
    while(scanf("%lld%lld",&l,&u)==2)
    {
        if(l==1)l++;
        segment_seive(l,u);

        for(i=0; i<segment.size(); i++)
        {
            if(segment[i])
                primeans.push_back(segment[i]);
        }
        if(primeans.size()<2)
        {
            cout<<"There are no adjacent primes."<<endl;
        }
        else
        {
            long long int x,y,mn=-1,mx=0;
            for(i=1; i<primeans.size(); i++)
            {
                k=primeans[i]-primeans[i-1];
                if(k<mn || mn==-1)
                {
                    mn=primeans[i]-primeans[i-1];
                    x=primeans[i-1];
                    y=primeans[i];
                }
            }
            cout<<x<<','<<y<<" are closest, ";
            for(i=1; i<primeans.size(); i++)
            {
                k=primeans[i]-primeans[i-1];
                if(k>mx)
                {
                    mx=primeans[i]-primeans[i-1];
                    x=primeans[i-1];
                    y=primeans[i];
                }
            }
            cout<<x<<','<<y<<" are most distant."<<endl;
        }
        primeans.clear();

    }
    return 0;
}


