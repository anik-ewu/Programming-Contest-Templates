///Date     : 18.8.2020
///Approach : Bridge Tree + LCA

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

///For Bridge Tree
vector<int> adj[maxn];
vector< int > tree[maxn];///Bridge Tree
int comp[maxn];/// Component In The Graph
int bicon[maxn];///Biconnected Component
int vis[maxn], low[maxn], tym = 1, c = 0;

///For LCA
int lavel[maxn];
int parent[maxn];
int table[maxn][100];

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

void build_bridge_tree(int n){

	c = 1;
	for(int i = 1; i <= n; i++)
		if(!vis[i]) calc(i, 0, c++);

	c = 1;
	vector<int> root;
	for(int i = 1; i <= n; i++) if(!bicon[i]) {
		root.push_back(c);
		shrink(i, c++);
    }
}

void dfs(int from, int u, int lv){
    lavel[u]=lv;
    parent[u]=from;
    for(int i=0; i<tree[u].size(); i++){
        int v=adj[u][i];
        if(v==from)continue;
        dfs(u, v, lv+1);
    }
}

void init(int n){

    memset(table, -1, sizeof(table));
    for(int i=0; i<n; i++){
        table[i][0]=parent[i];
    }
    for(int j=1; (1<<j)<n; j++){
        for(int i=0; i<n; i++){
            if(table[i][j-1]!=-1){
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }
    }
}

int lca(int a, int b){

    int log=1;
    if(lavel[a]<lavel[b])swap(a,b);
    while((1<<(log+1))>lavel[a])log++; ///calculating max level

    ///making level[a]==level[b]
    for(int i=log; i>=0; i--){
        if(lavel[a]-(1<<i)>=lavel[b])
            a=table[a][i];
    }
    if(a==b)return a;

    for(int i=log; i>=0; i--){
        if(table[a][i]!=-1 && table[a][i]!=table[b][i]){
            a=table[a][i];  b=table[b][i];
        }
    }
    return parent[a];
}

void solve(int q, int n){

    build_bridge_tree(n);
    ///component component in
    memset(vis,0,sizeof(vis));
    int compo=0;
    for(int i=1; i<=n; i++){
        if(vis[bicon[i]]==0){
            compo=0;
            vis[bicon[i]]==1;
        }
    }
    dfs(-1 , 1, 0);
    init(compo);
    int a, b, cc, d;

    while(q--){
        cin>>a>>b>>cc>>d;
        int tot=0;
        a=bicon[a];
        b=bicon[b];
        cc=bicon[cc];
        d=bicon[d];
        if(cc!=d){
            int L=lca(cc,d);
            tot=(lavel[cc]-lavel[L])+(lavel[d]-lavel[L]);

        }
        cout<<tot<<endl;
    }
}

int main(){

    int u,v,n,m,q;
    cin>>n>>m>>q;

    for(int i=1; i<=m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(q, n);

    return 0;
}


