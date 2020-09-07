///Date     : 13/5/2020
///ALGO     : Dynamic Programming ( Digit DP) + Binary Search

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll unsigned long long

int len;
string s;
ll dp[25][2][10];
bool mark[20][2][10];

ll cal(int pos, bool smaller, int prev){

    if(pos>=len)return 1;
    if(mark[pos][smaller][prev]!=true)return dp[pos][smaller][prev];
    ll total=0;
    ll limit=9;
    if(!smaller)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        if(i==4 ||(prev==1 && i==3))continue;
        total+=cal(pos+1, smaller||(i<limit), i);
    }

    mark[pos][smaller][prev]=false;
    return dp[pos][smaller][prev]=total;
}

void convert(ll n){
    stringstream ss;
    ss<<n;
    ss>>s;
}

ll pp(ll n){

    ll lo=n;
    ll hi=n*100;
    ll mid;
    while(hi-lo>2){
        ll mid=(lo+hi)/2;
        convert(mid);
        len=s.size();
        memset(dp,0,sizeof(dp));
        if(cal(0,0,0)-1>=n){
            hi=mid;
        }
        else{
            lo=hi;
        }
    }
    while(true){
        convert(hi-1);
        len=s.size();
        memset(dp,0,sizeof(dp));
        memset(mark,true,sizeof(mark));
        if(cal(0,0,0)-1>=n){
            hi--;
        }
        else return hi;
    }
}

int main(){
    fast;
    ll n;
    while(cin>>n){
        cout<<pp(n)<<endl;
    }
    return 0;
}
