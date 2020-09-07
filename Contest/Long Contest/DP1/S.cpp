#include<bits/stdc++.h>
using namespace std;
int mn;
string s,p;
int dp[1001][1001];

int cal(int i, int j){
    if(i==s.size())return p.size()-j;
    if(j==p.size())return s.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==p[j]) return dp[i][j]=cal(i+1,j+1);
    int a=1+cal(i+1,j);
    int b=1+cal(i,j+1);
    return dp[i][j]=min(a,b);
}

void path(int i, int j){
    if(i==s.size()){
        for(int k=j; k<p.size(); k++)cout<<p[k];
        return;
    }
    if(j==p.size()){
        for(int k=i; k<s.size(); k++)cout<<s[k];
        return;
    }
    int val=cal(i,j);
    int val2=1+cal(i+1,j);
    int val3=1+cal(i,j+1);
    ///cout<<i<<' '<<j<<' '<<val<<' '<<val2<<' '<<val3<<endl;
    if(1+cal(i+1,j)==val){
        cout<<s[i];
        path(i+1,j);
    }
    else if(1+cal(i,j+1)==val){
        cout<<p[i];
        path(i,j+1);
    }
    else{
        cout<<s[j];
        path(i+1,j+1);
    }
}

int main(){

    int t,cs=1;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>s;
        p=s;
        reverse(p.begin(),p.end());
        cout<<p<<endl;
        int mn=cal(0,0);
        cout<<mn/2<<' ';
        path(0,0);
        cout<<endl;

    }
    return 0;
}
