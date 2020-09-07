#include<bits/stdc++.h>
using namespace std;
string s,p;
int dp[1001][1001];

int cal(int i, int j, int n, int m){

    if(i>=n) return m-j;
    if(j>=m) return n-i;
    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i]==p[j])
        return dp[i][j]=cal(i+1,j+1,n,m);


    int a=1+cal(i+1,j,n,m);
    int b=1+cal(i,j+1,n,m);
    int c=1+cal(i+1,j+1,n,m);
    return dp[i][j]=min(a,min(b,c));
}

int main(){

    int n,m;
    while(cin>>n>>s>>m>>p){
        memset(dp,-1,sizeof(dp));
        cout<<cal(0,0,n,m)<<endl;
    }
    return 0;
}
