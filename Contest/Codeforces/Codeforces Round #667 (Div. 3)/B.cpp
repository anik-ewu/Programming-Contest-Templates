#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
const ll mod = 1e9+7;

#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              3000005

int main(){
    Fast;///using Fast I/O
    ll a,b,c, i,j,k, t,n,m,x,y;

    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y>>n;
        c=(a-x)+(b-y);
        ll ans;
        if(c<=n){
            ans=x*y;
        }
        else{
            i=a-n;
            i=max(i,x);

            j=b-n;
            j=max(j,y);

            if(i<=j){
                if(a-x<=n){
                    n-=(a-x);
                    a=x;
                    b=b-n;
                }
                else{
                   a=a-n;
                }
            }
            else{
                if(b-y<=n){
                    n-=(b-y);
                    b=y;
                    a=a-n;
                }
                else{
                    b=b-n;
                }
            }
            ans=a*b;
        }
        cout<<ans<<endl;

    }

    return 0;
}


