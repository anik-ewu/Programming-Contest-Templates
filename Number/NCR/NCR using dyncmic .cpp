#include<bits/stdc++.h>
#define i64 unsigned long long
using namespace std;

i64 dp[10001][33];
i64 nCr(int n, int r){
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    ///if(n==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (i64)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main(){
    int n, r;
    while(scanf("%d %d",&n,&r)==2){
        r = (r<n-r)? r : n-r;
        printf("%llu\n",nCr(n,r));
        for(int i=1; i<=20; i++){
            cout<<dp[i][4]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
