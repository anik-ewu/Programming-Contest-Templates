#include<bits/stdc++.h>
using namespace std;

long long int dp[50][50];

long long int cal(int pos, int n, int col){

    if(pos==n && col==2)return 0;
    if(pos==n && col!=2)return 1;

    if(dp[pos][col]!=-1)return dp[pos][col];
    long long int sum=0;
    if(col==1)
        sum=cal(pos+1,n,2)+cal(pos+1,n,3);
    else if(col==2)
        sum=cal(pos+1,n,1);
    else
        sum+=cal(pos+1,n,1)+cal(pos+1,n,2);

    return dp[pos][col]=sum;

}

int main(){

    memset(dp,-1,sizeof(dp));
    long long int n,ans;
    cin>>n;
    ans=cal(1,n,1)+cal(1,n,3);
    cout<<ans<<endl;


    return 0;
}
