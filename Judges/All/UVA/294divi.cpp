#include<bits/stdc++.h>
using namespace std;

int divisor(long long int n)
{
    int i,sum=0;
    for(i=1; i*i<n; i++)
    {
        if(n%i==0)
        {
            sum+=2;
        }
    }
    if(i*i==n)
        sum+=1;
    return sum;
}
int main()
{
    long long int n,a,b,c,d,i,j,k,x,y;
    cin>>n;
    while(n>0)
    {
        cin>>a>>b;
        x=0; y=0;
        for(i=a; i<=b; i++)
        {
            c=divisor(i);
            if(c>x)
            {
                x=c;
                y=i;
            }
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<y<<" has a maximum of "<<x<<" divisors."<<endl;
        n--;
    }
    return 0;
}
