#include<bits/stdc++.h>
using namespace std;
string s,p;
int ex,n,m;
int dp[81][81];
int cal(int i, int j){
    if(i>=n) return m-j;
    if(j>=m) return n-i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==p[j])
        return dp[i][j]=cal(i+1,j+1);
    int a=1+cal(i+1,j);
    int b=1+cal(i,j+1);
    int c=1+cal(i+1,j+1);
    return dp[i][j]=min(a,min(b,c));
}

void path(int i, int j, int len, int add, int op){

    if(i>=n){
        for(int k=j; k<m; k++){
            cout<<op<<' '<<"Insert "<<k+1<<','<<p[k]<<endl;
            op++;
        }
        return;
    }
    if(j>=m){
        for(int k=i; k<n; k++){
            cout<<op<<' '<<"Delete "<<k+1+add<<endl;
            op++;add--;
        }
        return ;
    }
    if(s[i]==p[j]){
        path(i+1,j+1,len,add,op);
    }
    else if(cal(i+1,j)+1==len){
        cout<<op<<" Delete "<<i+1+add<<endl;
        path(i+1,j,len-1,add-1,op+1);
    }
    else if(cal(i,j+1)+1==len){
        cout<<op<<" Insert "<<i+1+add<<','<<p[j]<<endl;
        path(i,j+1,len-1,add+1,op+1);

    }
    else {
        cout<<op<<" Replace "<<i+1+add<<','<<p[j]<<endl;
        path(i+1,j+1,len-1,add,op+1);
    }
}



int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int cs=0;
    while(cin>>s){
        cin>>p;
        n=s.size();
        m=p.size();
        memset(dp,-1,sizeof(dp));
        if(cs)cout<<endl;
        cout<<cal(0,0)<<endl;
        path(0,0,cal(0,0),0,1);
        cs=1;
    }
    return 0;
}
