///Date     : 20-7-2020
///Approach : Binary Search

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e20

bool check(int m, long double x, long double mid){
    return m>mid-((mid/100.0)*x);
}

int solve(ll int m, double x){

    if(x==0) return max(m-2,1LL*0);
    if(x==100) return max(m-2,1LL*0);

    ll int lo=0;
    ll int hi=inf;

    while(hi-lo>2){
        ll int mid=(lo+hi)/2;

        if(check(m, x, mid)){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    while(check(m, x, lo+1))lo++;

    return lo;
}

int main(){

    int m, x;
    while(cin>>m>>x){
        if(m==0 && x==0)break;
        cout<<solve(m,x)<<endl;
    }

    return 0;
}
