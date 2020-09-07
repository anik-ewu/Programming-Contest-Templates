#include<bits/stdc++.h>
using namespace std;

#define sz 1500000
int arr[sz+2],ans[sz+2];
bool mark[sz+2];
vector < long long int > prime;

void seive()
{
    int i,j;
    for(i=1; i<sz; i++)
        mark[i]=true;
    for(i=4; i<sz; i+=2)
        mark[i]=false;

    mark[2]=true;
    for(i=3; i*i<sz; i++)
    {
        if(mark[i])
        {
            for(j=i*i; j<sz; j+=(i*2))
                mark[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3; i<sz; i+=2)
        if(mark[i])
            prime.push_back(i);
}

void precal_factors()
{
    int n,k,i,j;
    ans[1]=0;
    for(i=2; i<=1000002; i++)
    {
        ans[i]=ans[i-1];
        n=i;
        j=0;
        while(mark[n]==false and n>1)
        {
            if(n%prime[j]==0)
            {
                ans[i]++;
                n/=prime[j];
            }
            else j++;
        }
        if(mark[n]==true and n>1)
            ans[i]++;
    }
}



int main()
{
    seive();
    precal_factors();
    int n,i,j,x,y;
    while(scanf("%d",&n)==1)
    {

        printf("%d\n",ans[n]);
    }

    return 0;
}
