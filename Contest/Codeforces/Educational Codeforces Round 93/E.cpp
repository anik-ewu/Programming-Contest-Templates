#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              205

ll dp[sz][sz][sz];
ll r[sz],g[sz],b[sz];

ll f(int i, int j, int k){
    if(!(i|j) || !(j|k) || !(i|k))return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    ll x=0,y=0,z=0;
    if(i && j)x=(r[i]*g[j])+f(i-1,j-1,k);
    if(i && k)y=(r[i]*b[k])+f(i-1,j,k-1);
    if(j && k)z=(g[j]*b[k])+f(i,j-1,k-1);
    return dp[i][j][k]=max(x,max(y,z));
}

int main(){
    Fast;///using Fast I/O;

    ll n,m,p,i;
    cin>>n>>m>>p;

    for(i=1; i<=n; i++)cin>>r[i];
    for(i=1; i<=m; i++)cin>>g[i];
    for(i=1; i<=p; i++)cin>>b[i];

    sort(r+1,r+n+1);
    sort(g+1,g+m+1);
    sort(b+1,b+p+1);

    memset(dp,-1,sizeof(dp));
    cout<<f(n,m,p)<<endl;

    return 0;
}

