#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              3000005


int main(){
    Fast;///using Fast I/O

    ll n,m, p, r, tot;
    cin>>n>>p>>r;

    n=n%p;
    m=(n*(n+1))/2;
    tot=(m*m);

    if(tot%p==r){
        cout<<p-(tot%p)<<' '<<tot%p<<endl;
    }
    else{
        cout<<(tot%p)<<' '<<p-(tot%p)<<endl;
    }


    return 0;
}

