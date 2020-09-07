#include<bits/stdc++.h>
using namespace std;
#define sz 1001
int dp[sz][sz];

int LCM(string s, string p){
    memset(dp,0,sizeof(dp));
    int n=s.size();
    int m=p.size();
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(s[i-1]==p[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){

    string s,p;
    while(getline(cin,s)){
        getline(cin,p);
        cout<<LCM(s,p)<<endl;
    }


    return 0;
}
