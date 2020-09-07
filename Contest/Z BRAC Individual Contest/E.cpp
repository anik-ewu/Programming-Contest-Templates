#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1e9+7
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              3000005


ll binomialCoeff(ll n, ll k){
    ll res = 1;
    if (k>n-k)k = n - k;
    for (ll i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void solve(double n, double k){

    long double sum=0;
    long double tot=1;
    for(double i=1; i<=n; i++){
        if((i*100.0/n)>=k){
            sum+=binomialCoeff(n,i);
        }
        tot+=binomialCoeff(n,i);
    }
    double ans=sum/tot;

    printf("%0.2f\n",ans);
    ///cout <<setprecision(2) << ans <<endl;

}

int main(){
    int t,n,k;

    cin>>t;
    while(t--){
        cin>>n>>k;
        solve(n,k);
    }

    return 0;
}

