#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,c,r,i,j,x,y,k,ans=1;
    int a[200],b[200];
    while(cin>>n>>r)
    {
        if(n==0 && r==0)break;
        for(i=1; i<=n; i++)
        {
            a[i]=i;
            if(i<=r)
                b[i]=i;
        }
        j=n-r;
        for(i=1; i<=r; i++)
        {
            for(k=j+1; k<=n; k++)
            {

                if(a[k]%b[i]==0 && b[i]>1)
                {
                    a[k]/=b[i];
                    b[i]=1;
                    break;
                }
                else
                {
                    c=__gcd(a[k],b[i]);
                    if(c>1)
                    {
                        a[k]/=c;
                        b[i]/=c;
                    }
                }
            }
        }
        ans=1;
        for(i=j+1; i<=n; i++)
        {
            ans*=a[i];
        }
        cout<<n<<" things taken "<<r<<" at a time is "<<ans<<" exactly."<<endl;

    }
    return 0;
}
