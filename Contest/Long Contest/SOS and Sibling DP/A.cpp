#include<bits/stdc++.h>
using namespace std;
const int K=22, N=1<<K;

int dp[N], arr[N];

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[arr[i]]=arr[i];
    }

    for(int i=0; i<K; i++){
       for(int mask=0; mask<N; mask++){
        if(mask & (1<<i)){
            dp[mask]=max(dp[mask],dp[mask^(1<<i)]);
        }
       }
    }
    for(i=0; i<n; i++){
        cout<<dp[N-1^arr[i]]<<' ';
    }
    return 0;
}

