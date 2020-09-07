///Bridge Tree+ SCC + DP

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int dp[maxn];
int comp[maxn], bicon[maxn];
vector<int> adj[maxn], tree[maxn];
int vis[maxn], low[maxn], tym = 1, c = 0;

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
			tree[now].push_back(c);
			tree[c].push_back(now);
			shrink(v, c++);
		} else shrink(v, now);
	}
}

int dfs(int u, int par){

    int r=dp[u]-1;
    for(int i=0; i<tree[i].size(); i++){
        int v=tree[u][i];
        if(v!=par){
            r=r+dfs(v,u);
        }
    }
    return r;
}

int solve(int n){

        c = 1;
        for(int i = 1; i <= n; i++)
        if(!vis[i]) calc(i, 0, c++);

        c = 1;
        vector<int> root;
        for(int i = 1; i <= n; i++) if(!bicon[i]) {
            root.push_back(c);
            shrink(i, c++);
        }

        for(int i=1; i<=n; i++){
            dp[bicon[i]]++;
        }
        int arr[maxn];
        memset(arr,0,sizeof(arr));

        int mx=0;
        for(int i=0; i<root.size(); i++){
           int tot=dfs(root[i],0);
           cout<<tot<<endl;
           if(tot>mx)mx=tot;
           arr[root[i]]=tot;
        }

        for(int i=1; i<=n; i++){
            if(arr[bicon[i]]==mx)return i;
        }
}

void clr(int n){
    tym=1;
    for(int i=0; i<=n; i++){
        adj[i].clear();
        tree[i].clear();
        dp[i]=low[i]=vis[i]=bicon[i]=0;
    }
}

int main(){

    int t, cs= 1, u,v,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        clr(n);
        for(int i=1; i<=n; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout<<"Case "<<cs++<<": "<<solve(n)<<endl;

    }

    return 0;
}
