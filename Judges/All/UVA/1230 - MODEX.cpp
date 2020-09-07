///Date     : 29.5.2020
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll binpow(ll b, ll p , ll m){
    if(p==0)return 1;
    ll res=binpow(b,p/2,m);
    if(p%2)
        return  res * res * b %m;
    else return res * res %m;
}

int main(){
    Fast;
    ll t,x,y,n;
    while(cin>>t){
        if(!t)break;
        while(t--){
            cin>>x>>y>>n;
            cout<<binpow(x,y,n)<<endl;
        }
    }

    return 0;
}
