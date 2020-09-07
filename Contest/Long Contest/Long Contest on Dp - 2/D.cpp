#include<bits/stdc++.h>
using namespace std;
#define Sz 1001

string s;
int len;
int dp[Sz][Sz];
int Nxt[Sz][26];
int pre[Sz][26];

int cal(int l, int r){
    if(l>r)return 0;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    if(s[l]==s[r])return dp[l][r]=2+cal(l+1,r-1);
    return dp[l][r]=max(cal(l+1,r),cal(l,r-1));
}


void nxt_arr(int sz){
    for(int i=0; i<=sz; i++){
        for(int x=0; x<27; x++){
            Nxt[i][x]=-1;
        }
        for(int j=sz; j>i; j--){
            Nxt[i][s[j]-'a']=j;
        }
    }

    for(int i=sz; i>=0; i--){
        for(int x=0; x<27; x++){
            pre[i][x]=-1;
        }
        for(int j=0; j<i; j++){
            pre[i][s[j]-'a']=j;
        }
    }
}

void path(int l, int r, int step){

    if(step<=0){
        return;
    }
    int i,j;
    for(int k=0; k<26; k++){
        i=Nxt[l][k];
        j=pre[r][k];
        if(i==-1||j==-1)continue;
        if(cal(i,j)==step){
            cout<<char(k+'a');
            path(i,j,step-2);
           /// if(i!=j)
                ///cout<<char(k+'a');
            break;
        }
    }
}

int main(){

    while(cin>>s){
        s.insert(s.begin(),'A');
        s.insert(s.end(),'A');
        memset(dp,-1,sizeof(dp));

        len=cal(1,s.size()-1);

        nxt_arr(s.size()-1);

        path(0,s.size()-1,len);

        cout<<endl;

    }

    return 0;
}
