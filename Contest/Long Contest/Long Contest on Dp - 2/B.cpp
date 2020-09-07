#include<bits/stdc++.h>
using namespace std;
int tot,n;
int arr[101];
int dp[101][50001];
int cal(int p, int sum){
    if(p>n)return abs(sum-(tot-sum));
    if(dp[p][sum]!=-1)return dp[p][sum];
    return dp[p][sum]=min(cal(p+1,sum),cal(p+1,sum+arr[p]));
}
int main(){
    int t,i;
    cin>>t;
    while(t--){
        cin>>n;
        tot=0;
        for(i=1; i<=n; i++)cin>>arr[i],tot+=arr[i];
        memset(dp,-1,sizeof(dp));
        cout<<cal(1,0)<<endl;
    }
    return 0;
}
