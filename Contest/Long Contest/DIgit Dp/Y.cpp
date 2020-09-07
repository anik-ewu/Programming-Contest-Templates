///Date     : 11/5/2020
///ALGO     : Dynamic Programming ( Digit DP)
///Notes    : ***
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int len;
string s;
ll dp[20][2][1000];
ll f(int pos, bool small, ll cnt){
    if(pos==len)return cnt;
    if(dp[pos][small][cnt]!=-1)return dp[pos][small][cnt];
    ll sum=0;
    int limit=9;
    if(!small)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        sum+=f(pos+1, small||(i<limit), cnt+i);
    }
    return dp[pos][small][cnt]=sum;
}

void convert(ll n){
    stringstream ss;
    ss<<n;
    ss>>s;
}

int main(){
    fast;
    ll sum,cs=1,l,r;
    while( cin>>l>>r){
       if(l==-1 && r==-1)break;

       convert(r);
       len=s.size();
       memset(dp,-1,sizeof(dp));
       sum=f(0,0,0);

       convert(l-1);
       len=s.size();
       memset(dp,-1,sizeof(dp));
       if(l-1>0)sum-=f(0,0,0);

       cout<<sum<<endl;
    }
    return 0;
}

