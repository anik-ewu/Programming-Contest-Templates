///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[201][101];///size : n+r
#define mod  1000000

ll ncr(int n, int r){
    if(n==0 || r==0)return 1;
    if(r==1)return n;
    if(n==r)return 1;
    if(dp[n][r]!=-1)return dp[n][r]%mod;
    return dp[n][r]=((ncr(n-1,r))%mod+(ncr(n-1,r-1)%mod))%mod;
}
int main(){

    ll n,r;
    while(cin>>n>>r){
        if(n==0 && r==0)break;
        memset(dp,-1,sizeof(dp));
        cout<<ncr(n+r-1,r-1)<<endl;
    }
    return 0;
}
