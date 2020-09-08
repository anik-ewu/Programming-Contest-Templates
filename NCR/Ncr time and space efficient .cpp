///Binomial Coefficient : nCr
///Time Complexity      : O(k)
///Memory Complexity    : O(1)

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll binomialCoeff(ll n, ll k){
    ll res = 1;
    if (k>n-k)k = n - k;
    for (ll i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    ll n, m;

    while(cin>>n>>m)
    {
        if(n==0 and m==0)
            break;

        ll ans=binomialCoeff(n,m);

        cout<<ans<<endl;
    }
    return 0;
}
