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

int sum_x(ll x){

    int sum=0;
    while(x){
        sum+=(x%10);
        x/=10;
    }
    return sum;
}

ll process(ll x){

    ll i=0;
    ll y=x;
    while(x%10==0){
        x/=10;
        i++;
    }
    ll j=1;
    while(i--)j*=10;

    y=y+(j*(10-x%10));
    return y;
}

int main(){
    Fast;///using Fast I/O

    ll a,b,c, x, i,j,k, t,n,m;
    cin>>t;
    while(t--){
       cin>>x>>n;

       ///make the final number
       ll prev=x;
       while(sum_x(x)>n){
           x=process(x);
       }
       cout<<x-prev<<endl;
    }

    return 0;
}

