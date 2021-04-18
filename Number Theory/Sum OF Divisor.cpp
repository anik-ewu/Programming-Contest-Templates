#include<bits/stdc++.h>
using namespace std;
#define S 10000002

typedef long long ll;
bool mark[S+7];
vector < int > prime;
void  seive()
{
    int i,j,k,x;

    for(int i=1; i<S; i++)
        mark[i]=true;
    mark[1]=false;
    for(i=4; i<=S; i+=2)
        mark[i]=false;
    for(i=3; i*i<=S; i+=2)
    {
        if(mark[i]==true)
        {
            for(j=i*i; j<S; j+=i+i)
                mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3; i<=S; i+=2)
    {
        if(mark[i]==true)
            prime.push_back(i);
    }
}

int sod(ll n)
{
    ll i,val,con,sum,p,s;
    sum=1;
    for(i=0; (prime[i]*1LL*prime[i])<=n; i++)
    {
        if(n%prime[i]==0)
        {
            p=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                p*=prime[i];
            }
            p*=prime[i];
            s=(p-1)/(prime[i]-1);
            sum*=s;
        }
    }
    if(n>1)
    {
        p=n*n;
        s=(p-1)/(n-1);
        sum*=s;
    }
    return sum;

}



int main()
{
    seive();
    int n;
    cin>>n;
    cout<<sod(n);
}

