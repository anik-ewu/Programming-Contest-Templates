#include<bits/stdc++.h>
using namespace std;
#define mx INT_MAX
#define ll long long
int n;
string s;
ll dp[205];

ll pp(ll num, ll x){
    return (num*10)+x;
}

ll cal(int p){

    if(p>=n){
        return 0;
    }

    if(dp[p]!=-1)return dp[p];

    ll a,b,num=0,c=0;
    a=s[p]-'0'+cal(p+1);
    for(int i=p; i<p+12 && i<n; i++){
        num=num*10+s[i]-'0';
        if(num<=mx){
          b=num+cal(i+1);
        }
        /// we are doing this as because b will not always be the bigger one in the end
        c=max(b,c);
    }
    return dp[p]=max(c,a);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        n=s.size();
        memset(dp,-1,sizeof(dp));
        cout<<cal(0)<<endl;
    }
    return 0;
}
