///Date     : 18.8.2020
///Approach : Bridge Tree

#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<int> adj[maxn], tree[maxn];

int good[maxn];
int len, root;
int comp[maxn], bicon[maxn], par[maxn];
int vis[maxn], low[maxn], tym = 1, c = 0;
map < pair< int, int > , int > mp;
map < pair< int, int > , int > mpp;

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
			mpp[{now,c}]=mp[{u,v}];
			mpp[{c,now}]=mp[{u,v}];

			shrink(v, c++);
		} else shrink(v, now);
	}
}

void build(int n){
    for(int i=1; i<=n; i++){
      for(int j=0; j<adj[i].size(); j++){
        int u=i;
        int v=adj[i][j];
        if(mp[{u,v}]==1 && bicon[u]==bicon[v]){
            good[bicon[u]]=1;
        }
      }
    }
}

bool bfs(int s, int d){

    queue<int> q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<tree[u].size(); i++){
            int v=tree[u][i];
            if(vis[v]==0){
                par[v]=u;
                vis[v]=1;
                q.push(v);
            }
        }
    }
    while(d!=s){
        int u=par[d];
        int v=d;
        if(mpp[{u,v}] || good[u] || good[v])return true;
        d=par[d];
    }
    return false;
}

string solve(int n){

    int src, des;
    cin>>src>>des;

    build(n);

    bool possible=good[bicon[src]];
    possible=possible || bfs(bicon[src],bicon[des]);
    if(possible)return "Yes";
    return "No";
}

int main(){

    int u,v,key,n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++){
        cin>>u>>v>>key;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=key;
        mp[{v,u}]=key;
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

