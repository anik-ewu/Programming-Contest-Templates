#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz 200
#define inf 1<<16

ll dp[sz][sz];

void cal(int n){
    int i,j;
    for(i=2; i<=n; i++){
        for(j=1; j<=i; j++){
            ll a=dp[i][j]+dp[i-1][j];
            ll b=dp[i][j]+dp[i-1][j-1];
            dp[i][j]=max(a,b);
        }
    }
    ll nn=n-1;
    for(i=n+1; i<2*n; i++){
        for(j=1; j<=nn; j++){
            ll a=dp[i][j]+dp[i-1][j];
            ll b=dp[i][j]+dp[i-1][j+1];
            dp[i][j]=max(a,b);
        }
    }
}
int main(){

    ll t,i,j,n,cs=1;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++){
            for(j=1; j<=i; j++){
                scanf("%lld",&dp[i][j]);///cin>>arr[i][j];
            }
        }
        int mm=n-1;
        for(i=n+1; i<(n*2); i++){
            for(j=1; j<=mm; j++){
                scanf("%lld",&dp[i][j]);///cin>>arr[i][j];
            }
            mm--;
        }
        cal(n);
        ll ans=dp[n*2-1][1];
        printf("Case %lld: %lld\n",cs++,ans);
    }

    return 0;
}
