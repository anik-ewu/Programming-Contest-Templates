///complexity: n*2^n n represents bits no
int dp[1<<n][n];
int sos_dp(int mask, int x){
    if(x==-1) return sos[mask];
    if(dp[mask][x]!=-1)return dp[mask][x];
    ///xth bit is on
    if(mask & (1<<x)!=0){
       return dp[mask][x]=sos_dp(mask,x-1)+sos_dp(mask^(1<x),x-1);
    }
    else{
        return dp[mask][x]=sos_dp(mask,x-1);
    }
}
