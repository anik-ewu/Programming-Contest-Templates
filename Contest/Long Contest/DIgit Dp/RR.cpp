///Date     : 1.6.2020
///Approach : Digit DP + Bit Mask
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int n,m;
int dp[105][10][(1<<10)+5];

int cal(int pos, int prev, int mask){
    if(pos>=m)return 0;
    if(dp[pos][prev][mask]!=-1)return dp[pos][prev][mask]%mod;
    int sum=0;
    if(mask==(1<<n)-1)sum++;
    for(int i=prev-1; i<=prev+1; i+=2){
        if(i<0 || i>=n)continue;
        sum=(sum+(cal(pos+1,i,mask|(1<<i))%mod))%mod;
    }
    return dp[pos][prev][mask]=sum%mod;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        int total=0;
        for(int i=1; i<n; i++){
            total+=cal(0,i,(1<<i));
            total=total%mod;
        }
        cout<<total<<endl;
    }
    return 0;
}
