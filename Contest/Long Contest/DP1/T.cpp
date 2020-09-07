#include<bits/stdc++.h>
using namespace std;
string s;
int dp[1001][1001];

int cal(int l, int r){

    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];

    if(s[l]==s[r])
        return dp[l][r]=cal(l+1,r-1);

    int a=1+cal(l+1,r);
    int b=1+cal(l,r-1);

    return dp[l][r]=min(a,b);
}

int main(){

    ///freopen("out.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    getchar();
    while(t--){
        memset(dp,-1,sizeof(dp));
        getline(cin,s);
        if(s.size()==0)
            cout<<0<<endl;
        else
            cout<<s.size()-cal(0,s.size()-1)<<endl;
    }
    return 0;
}

