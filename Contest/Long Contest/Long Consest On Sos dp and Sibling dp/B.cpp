///Date: 1-9-2020
///Approach:sos dp + inclusion exclusion

#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int K=20, N=1<<K;
typedef long long ll;
ll dp[N];
ll po[N];


int main(){

    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        dp[x]++;
    }
    po[0]=1;
    for(int i=1; i<N; i++){
        po[i]=(po[i-1]+po[i-1]);
        if(po[i]>=mod)po[i]-=mod;
    }

    for(int i=0; i<K; i++){
        for(int mask=0; mask<N; mask++){
            if((mask&(1<<i))==0){
                dp[mask]+=dp[mask^(1<<i)];
            }
        }
    }

    ll ans=0;
    for(int mask=0; mask<N; mask++){
        if(__builtin_popcount(mask)%2){
            ans-=(po[dp[mask]]-1);
        }
        else{
            ans+=(po[dp[mask]]-1);
        }
        ans=(ans+mod)%mod;
    }
    cout<<ans<<endl;

    return 0;
}
