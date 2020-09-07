///SOS DP

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1e9+7
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              4000005

const int K=22, N=1<<K;

int dp[N];
int arr[N];

int main(){
    Fast;///using Fast I/O
    int n, i;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(i=0; i<n; i++){
        cin>>arr[i];
        dp[arr[i]]=arr[i];
    }

    for(i=0; i<K; i++){
       for(int mask=0; mask<N; mask++){
        if(mask & (1<<i)){
            dp[mask]=max(dp[mask],dp[mask^(1<<i)]);
        }
       }
    }
    for(i=0; i<n; i++){
        cout<<dp[N-1^arr[i]]<<' ';
    }
    return 0;
}

