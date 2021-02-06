#include<bits/stdc++.h>
using namespace std;
#define Sz 1005

int t,root;
vector< int > adj[Sz];
int vis[Sz],d[Sz],p[Sz],low[Sz],point[Sz];

void dfs_visit(int u){
    int i,j,v,child=0;
    vis[u]=1;
    t++;
    d[u]=low[u]=t;

    for(int i=0; i<adj[u].size(); i++){
        child++;
        int v=adj[u][i];
        if(vis[v]==0){

            p[v]=u;
            dfs_visit(v);

            if(p[u]==0 && child>1)      point[u]=1;

            low[u]=min(low[u],low[v]);

            if(p[u]!=0 && low[v]>=d[u]) point[u]=1;

        }
        else if(v!=p[u]){
            low[u]=min(low[u],d[v]);
        }
    }
}
