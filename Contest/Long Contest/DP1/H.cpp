#include<bits/stdc++.h>
using namespace std;
#define mod 100000007

#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
int arr[51];///value
int brr[51];///frequency
int dp[51][1001];

int cal(int pos, int sum, int m){

    if(sum==m)return 1;
    if(pos>n || sum>m)return 0;

    if(dp[pos][sum]!=-1)return dp[pos][sum]%mod;

    int cnt=0;
    for(int i=0; i<=brr[pos]; i++){
        cnt+=(cal(pos+1,sum+(arr[pos]*i),m))%mod;
    }
    return dp[pos][sum]=cnt%mod;


}

int main(){

    FastRead
    int k,i,j,m,a,b,c,ans,t;
    cin>>t;
    for(i=1; i<=t; i++){
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        for(j=1; j<=n; j++)cin>>arr[j];
        for(j=1; j<=n; j++)cin>>brr[j];
        ans=cal(1,0,k);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
