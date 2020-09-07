#include<bits/stdc++.h>
using namespace std;
#define sz 101
string S;
int dp[sz][sz];
int cal(int s, int e){
    if(s>e)return 0;
    if(dp[s][e]!=-1)return dp[s][e];
    int a=1+cal(s+1,e);
    if(S[s]=='(' || S[s]=='['){
        for(int i=s+1; i<=e; i++){
            if((S[s]=='(' && S[i]==')')||(S[s]=='[' && S[i]==']')){
                a=min(a,cal(s+1,i-1)+cal(i+1,e));
            }
        }
    }
    return dp[s][e]=a;
}

void path(int s, int e){
    if(s>e){
        return;
    }
    int best=cal(s,e);
    if(1+cal(s+1,e)==best){
        if(S[s]=='(' || S[s]==')')cout<<"()";
        else cout<<"[]";
        path(s+1,e);
        return;
    }
    else{
        for(int i=s+1; i<=e; i++){
            if(((S[s]=='(' && S[i]==')')||(S[s]=='[' && S[i]==']'))&& best==cal(s+1,i-1)+cal(i+1,e)){
               if(S[s]=='('){
                    cout<<'(';
                    path(s+1,i-1);
                    cout<<')';
                    path(i+1,e);
                  }
                   else{
                    cout<<'[';
                    path(s+1,i-1);
                    cout<<']';
                    path(i+1,e);
                  }
                  return;
            }
        }
    }
}

int main(){
    getline(cin,S);
    memset(dp,-1,sizeof(dp));
    path(0,S.size()-1);
    return 0;
}
