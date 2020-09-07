#include<bits/stdc++.h>
using namespace std;

long long int dp[512][512];
long long int cal(int sum, int need ,int n){
    if(sum==n)return 1;
    if(sum>n)return 0;

    if(dp[sum][need]!=-1)return dp[sum][need];
    long long int tot=0;
    for(int i=need+1; i<=n; i++){
         if(sum+i>n)break;
         tot+=cal(sum+i,i,n);
    }
    return dp[sum][need]= tot;
}

int main(){

    memset(dp,-1,sizeof(dp));
    long long int n,ans=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        if(i<n-i)ans+=cal(i,i,n);
    }
    cout<<ans<<endl;


    return 0;
}
