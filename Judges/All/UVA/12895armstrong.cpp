#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,e,f[150],i,j,k,x,y,z,n,sum;
    double r;
    cin>>n;
    while(n>0)
    {
        cin>>a;
        c=a;
        i=1;
        while(1)
        {
            if(a==0)break;
            f[i++]=a%10;
            a=a/10;
        }
        x=i-1;
        sum=0;
        for(i=1; i<=x; i++)
        {
            r=pow(f[i],x);
            sum+=r;
        }
        if(sum==c)
            cout<<"Armstrong"<<endl;
        else
            cout<<"Not Armstrong"<<endl;

        n--;
    }
    return 0;
}
