#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
#define sz              201
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m;
int arr[sz];
int brr[sz];
int dp[sz][sz][515];
vector < int > v[sz];


int f(int r, int c, int res){
	if(c==m ) return INT_MAX;
	if(r>n)return res;
	if(dp[r][c][res]!=-1)return dp[r][c][res];
	int a=f(r+1,0,res|v[r][c]);
	int b=f(r,c+1,res);
	return dp[r][c][res]=min(a,b);
}

int build(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int c=(arr[i]&brr[j]);
            v[i].push_back(c);
        }
    }
}


int main(){
    Fast;
    int a,b,c, i,j,k, t, cs=1;

    cin>>n>>m;
    for(i=1; i<=n; i++)cin>>arr[i];
    for(i=1; i<=m; i++)cin>>brr[i];
    build();
    memset(dp,-1,sizeof(dp));
    cout<<f(1,0,0)<<endl;

    return 0;
}

