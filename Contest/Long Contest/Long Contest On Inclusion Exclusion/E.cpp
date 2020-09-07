///Date     : 22.6.2020
///Approach : Inclusion Exclusion + Stars And Bars Method

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll arr[21];
ll invfac[21];
ll bigmod(ll b,ll p){
    if(p==0)return 1;
    ll res=bigmod(b,p/2)%mod;
    res=(res*res)%mod;
    if(p%2) res=(res*b)%mod;
    return res;
}

void modinvfac(){
    invfac[0]=1;
    for(int i=1; i<=20; i++){
        invfac[i] = (1LL*invfac[i-1]*bigmod(i,mod-2))%mod;
    }
}

///stars and bars | consider N=(n+k-1) | then N!/(k-1)!*(N-(k-1))!
ll f(ll n, ll sum){
    if(sum<0)return 0;
    sum=((sum+n-1)%mod +mod)%mod;
    ll ans=1;
    for(int i=0; i<n-1; i++){
        ans=(ans*(sum-i+mod))%mod;
    }
    ans=(ans*invfac[n-1])%mod;
    return ans;
}

int main(){

    modinvfac();///calculating inverse factorial

    ll n,s;
    cin>>n>>s;
    for(int i=0; i<n; i++)cin>>arr[i];

    ll ans=0;
    for(ll mask=0; mask<(1<<n); mask++){
        ll sum=s;
        for(int i=0; i<n; i++){
            if(mask&(1<<i)){
                sum-=arr[i]+1;
            }
        }
        /// applying the principle of inclusion exclusion
        if(__builtin_popcount(mask)%2)
            ans=(ans+mod-f(n,sum))%mod;
        else
           ans=(ans+f(n,sum))%mod;
    }
    cout<<ans<<endl;

    return 0;
}
