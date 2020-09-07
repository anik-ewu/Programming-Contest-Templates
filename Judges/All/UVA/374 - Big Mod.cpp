#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll big_mod(ll base, ll power, ll m)
{
    if(power==0) return 1;
    else if( power%2==1)
    {
        ll p1=base%m;
        ll p2=(big_mod(base,power-1,m))%m;
        return (p1*p2)%m;
    }
    else if(power%2==0)
    {
       ll p1=(big_mod(base,power/2,m))%m;
       return (p1*p1)%m;
    }
}


int main()
{
    ll b,p,m;
    while(cin>>b>>p>>m)
    {
    cout<<big_mod(b,p,m)<<endl;
    }
    return 0;
}
