///Date     : 2.6.2020
///Approach : Digit DP

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz  2001
#define mod 1000000007

string a,b,s;
int len,m,digit;
ll dp[sz][sz][2];

ll cal(int pos, int rem, int issmall){
    if(pos>=len)return rem==0;
    if(dp[pos][rem][issmall]!=-1)return dp[pos][rem][issmall]%mod;
    ll sum=0;
    int limit=9;
    if(!issmall)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        if(pos%2==0 && i==digit)continue;
        if(pos%2==1 && i!=digit)continue;
        sum=(sum+(cal(pos+1,(rem * 10 +i)%m, issmall|(i<limit))%mod))%mod;
    }
    return dp[pos][rem][issmall]=sum%mod;
}

bool check(string A){

    for(int i=0; i<A.size(); i++){
        if(i%2==0 && A[i]-'0'==digit)return false;
        if(i%2==1 && A[i]-'0'!=digit)return false;
    }

    int num=A[0]-'0';
    for(int i=1; i<A.size(); i++){
        num=((num*10)+(A[i]-'0'))%m;
    }
    return (num%m==0);
}

ll process(string x){
    s=x;
    len=s.size();
    memset(dp,-1,sizeof(dp));
    return cal(0,0,0)%mod;
}

int main(){

    ll total;
    cin>>m>>digit>>a>>b;
    total=process(b)-process(a);
    if(check(a))total++;
    cout<<(total+mod)%mod<<endl;

    return 0;
}
