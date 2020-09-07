#include<bits/stdc++.h>
using namespace std;
#define sz  1001
#define mod 1000000007

int k;
int len;
string s;
int dp[sz][2][sz];

bool check(int n){
    int cnt=1;
    ///int m=n;
    while(n>1){
        n=__builtin_popcount(n);
        cnt++;
    }
    if(cnt==k)
        return true;
    return false;
}


int cal(int pos, bool smaller, int bits){

    ///cout<<pos<<' '<<bits<<endl;
    if(pos>=len)return 0;
    ///if(dp[pos][smaller][bits]!=-1)return dp[pos][smaller][bits]%mod;

    int limit=1;
    int total=0;
    if(!smaller)limit=s[pos]-'0';

    for(int i=0; i<=limit; i++){
        total=((total+check(bits+i))%mod)+(cal(pos+1, smaller||(i<limit),bits+i)%mod)%mod;
    }
    return dp[pos][smaller][bits]=total%mod;
}

int main(){

    cin>>s>>k;
    len=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<cal(0,0,0)<<endl;

    return 0;
}
