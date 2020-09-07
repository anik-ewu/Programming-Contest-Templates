///19.8.2020
///Dp+Bridge

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define maxn            1005

int MOD;
int dp[maxn][maxn];
vector<int> adj[maxn];
int comp[maxn], bicon[maxn];
int vis[maxn], low[maxn], tym = 1, c = 0;
vector< pair< int , int > > bridges;
map< pair< int , int >, int  > edge;

int f(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                dp[i][j]=0;
            }
            else if(i==1 || j==1){
                dp[i][j]=1%MOD;
            }
            else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]) % MOD;
            }
        }
    }
}

void calc(int u, int par, int c) {
	comp[u] = c;
	vis[u] = low[u] = tym++;
	for(int v : adj[u]) {
		if(vis[v]) {
			if(v != par) low[u] = min(low[u], vis[v]);
			else par = -1;
		} else {
			calc(v, u, c);
			low[u] = min(low[u], low[v]);
		}
	}
}

void shrink(int u, int now) {
	bicon[u] = now;
	for(int v : adj[u]) if(!bicon[v]) {
		if(low[v] > vis[u]) {
            bridges.push_back({v,u});
			shrink(v, c++);
		} else shrink(v, now);
	}
}

void resetall(int n){
    tym=1;
    edge.clear();
    bridges.clear();
    for(int i=1; i<=n; i++){
        adj[i].clear();
        bicon[i]=vis[i]=low[i]=0;
    }
}

void dfs(int u , int x, int y){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if((u==x && v==y)||(u==y and v==x)){
            continue;
        }
        if(vis[v]==0)
            dfs(v,x,y);
    }
}

int solve(int n){

    int mx=0;
    for(int k=0; k<bridges.size(); k++){
        int a=bridges[k].first;
        int b=bridges[k].second;
        int sub=dp[a][b];

        if(edge[{a,b}]>1)continue;

        memset(vis,0,sizeof(vis));
        dfs(a,a,b);

        a=b=0;
        for(int i=1; i<=n; i++){
            if(vis[i])a=i;
            else b=i;
        }
        ///cout<<a<<' '<<b<<' '<<dp[a][b]<<endl;
        mx=max(mx,dp[a][b]-sub);
        ///cout<<mx<<endl;
    }
    return mx;
}

int main(){
    ///Fast;///using Fast I/O
    int t,a,b,n,m;
    cin>>t;
    while(t--){

        cin>>n>>m>>MOD;
        resetall(n);
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edge[{a,b}]++;
            edge[{b,a}]++;
        }

        f(n);///precal

        c = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i]) calc(i, 0, c++);

        c = 1;
        vector<int> root;
        for(int i = 1; i <= n; i++) if(!bicon[i]) {
            root.push_back(c);
            shrink(i, c++);
        }

        cout<<solve(n)<<endl;
    }
    return 0;
}
