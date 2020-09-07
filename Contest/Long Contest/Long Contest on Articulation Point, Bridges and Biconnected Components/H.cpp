///Date     : 18.8.2020
///Approach : Bridge Tree+ BFS
///Idea     : Make a bridge tree of the graph and find the diameter of that tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 3e5 + 10;
vector<int> adj[maxn], tree[maxn];

int len, root;
int comp[maxn], bicon[maxn];
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

void dfs_len(int v, int u, int deep){

    if(deep>len){
        len=deep;
        root=v;
    }
    for(int i=0; i<tree[v].size(); i++){
        int x=tree[v][i];
        if(x==u)continue;
        dfs_len(x,v,deep+1);
    }
}

int solve(int n){
    ///Find the diameter then count the depth of the tree
    len=-1;
    dfs_len(1,-1,0);

    len=-1;
    dfs_len(root,-1,0);

    return len;
}


int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);///using Fast I/O

    int u,v,i,n,m;
    cin>>n>>m;
    for(i=1; i<=m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

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

    return 0;
}


