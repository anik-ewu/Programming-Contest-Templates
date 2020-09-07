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

ll arr[sz];

void solve(int n){
    ll mx=arr[1];
    for(int i=1; i<=n; i++){
        mx=max(arr[i],mx);
    }
    for(int i=1; i<=n; i++){
        arr[i]=mx-arr[i];
    }
}

int main(){
    Fast;///using Fast I/O
    ll a,b,c, i,j,k, t,n,m;

    cin>>t;
    while(t--){
        cin>>n>>k;
        for(i=1; i<=n; i++)cin>>arr[i];
        k=k%2;
        if(k==0)k=2;

        while(k--){
            solve(n);
        }

        for(j=1; j<=n; j++){
            cout<<arr[j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}

