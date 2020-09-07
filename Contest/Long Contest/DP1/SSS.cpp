#include<bits/stdc++.h>
using namespace std;
int mn;
string s,p;
string ss,ff;
int dp[1001][1001];
int cal(int l, int r){
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    if(s[l]==s[r])  return dp[l][r]=cal(l+1,r-1);
    int a=1+cal(l+1,r);
    int b=1+cal(l,r-1);
    return dp[l][r]=min(a,b);
}

void path(int l, int r, int mn){
    if(l>r){
        reverse(ss.begin(),ss.end());
        cout<<ff<<ss<<endl;
        return;
    }
    if(s[l]==s[r] && l==r){
        ff+=s[l];
        path(l+1,r-1,mn);
    }
    else if(s[l]==s[r] && l!=r){
        ff+=s[l],ss+=s[r];
        path(l+1,r-1,mn);
    }
    else if(1+cal(l+1,r)==mn){
        ff+=s[l];ss+=s[l];
        path(l+1,r,mn-1);
    }
    else if(1+cal(l,r-1)){
        ff+=s[r];ss+=s[r];
        path(l,r-1,mn-1);
    }
}

int main(){
    while(cin>>s){
        memset(dp,-1,sizeof(dp));
        int len=cal(0,s.size()-1);
        cout<<len<<' ';
        ff="";ss="";
        path(0,s.size()-1,len);
    }
    return 0;
}
