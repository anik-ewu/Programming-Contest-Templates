#include<bits/stdc++.h>
using namespace std;
#define S 1000002
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
}


long long int big_mod(int base , int power, int mod)
{
    if(power==0)
        return 1;

    if(power%2==1)
    {
        long long int p1=base%mod;
        long long int p2=big_mod(base,power-1,mod)%mod;
        return (p1*p2)%mod;
    }
    else
    {
        long long int p1=big_mod(base,power/2,mod)%mod;
        return (p1*p1)%mod;
    }
}



int main()
{

    seive();
    long long int n,num,i;

    while(scanf("%lld",&num))
    {
        if(num==0)
            break;
        if(mark[num]==false)
        {
            for(i=2; i<num-1; i++)
            {
                if(big_mod(i,num,num)!=i)
                    break;
            }
            if(i==num-1 and mark[num]==false)
                printf("The number %d is a Carmichael number.\n",num);

            else
                printf("%d is normal.\n",num);
        }
            else
                printf("%d is normal.\n",num);
    }
    return 0;
}
