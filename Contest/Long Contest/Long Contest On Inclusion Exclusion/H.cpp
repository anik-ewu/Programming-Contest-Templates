#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[15];

int cnt(ll n, int k, ll mid){

    ll tot=0;
    for(int mask=1; mask<(1<<k); mask++){
        ll lcm=1;
        for(int i=0; i<k; i++){
            if(mask&(1<<i)){
                lcm=((lcm*arr[i])/__gcd(lcm,arr[i]));
            }
        }
        if(__builtin_popcount(mask)%2==1)   tot+=(mid/lcm);
        else    tot-=(mid/lcm);
    }
    return tot;
}

ll solve(ll n, int k){

    ll lo=1;
    ll hi=1e18;
    while(hi-lo>2){
        ll mid=(lo+hi)/2;
        ll tot=cnt(n,k,mid);
        if(tot>=n and cnt(n,k,tot)>=n){
            hi=tot;
        }
        else{
            lo=mid;
        }
    }
    for(int i=1; i<=4; i++){
        ll tot=cnt(n,k,hi-1);
        if(tot>=n and cnt(n,k,tot)>=n)hi--;
    }
    return hi;
}

int main(){

    int n,t,k,cs=0;
    cin>>t;
    while(t--){
        cin>>k>>n;
        for(int i=0; i<k; i++)cin>>arr[i];
        if(cs)cout<<' ';cs=1;
        cout<<solve(n,k);
    }
    return 0;
}
