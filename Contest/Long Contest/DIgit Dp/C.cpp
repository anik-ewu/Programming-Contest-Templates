#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int len;
string s;
ll dp[20][2][2][10];
ll f(int pos, bool small, bool sig, ll cnt){
    if(pos==len)return cnt;
    if(dp[pos][small][sig][cnt]!=-1)return dp[pos][small][sig][cnt];
    ll sum=0;
    int limit=9;
    if(!small)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        sum+=f(pos+1, small||(i<limit), sig||(i>0), cnt+(i==0 && sig));
    }
    return dp[pos][small][sig][cnt]=sum;
}

void convert(ll n){
    stringstream ss;
    ss<<n;
    ss>>s;
}

int main(){
    fast;
    ll zeros,t,cs=1,n,l,r;
    cin>>t;
    while(t--){
       cin>>l>>r;

       convert(r);
       len=s.size();
       memset(dp,-1,sizeof(dp));
       zeros=f(0,0,0,0)+1;

       convert(l-1);
       len=s.size();
       memset(dp,-1,sizeof(dp));
       if(l)zeros-=f(0,0,0,0)+1;

       cout<<"Case "<<cs++<<": "<<zeros<<endl;
    }



    return 0;
}
