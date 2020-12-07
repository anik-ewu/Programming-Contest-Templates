///10325 - The Lottery
///7-12-2020
///Inclusion Exclusion


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

ll arr[16];
ll LCM(ll a , ll b){
    return (a/__gcd(a,b))*b;
}

int main(){
    Fast;///using Fast I/O
    ll a,b,c, i,j,k, t,n,m;

    while(cin>>n>>m){
        for(i=0; i<m; i++)cin>>arr[i];

        int tot=n;
        ll lcm;
        for(int mask=1; mask<(1<<m); mask++){
            int cnt=0;
            lcm=1;
            for(int i=0; i<m; i++){
                if(mask&(1<<i)){
                    cnt++;
                    lcm=LCM(lcm, arr[i]);
                }
            }
            if(cnt%2==0)tot+=(n/lcm);
            if(cnt%2==1)tot-=(n/lcm);
        }

        cout<<tot<<endl;

    }

    return 0;
}


