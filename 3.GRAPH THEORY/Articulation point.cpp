#include<bits/stdc++.h>
using namespace std;

#define sz 101

int point[sz];
int par[sz];
vector <int > adj[sz];

void dfs(int u, int par){

    vis[u]=1;
    int child=0;
    d[u]=f[u]=tym++;

    for(int v: adj[u]){
        if(v==par)continue;
        cout<<u<<' '<<v<<endl;
        dfs(v, u, child);
    }

}

int main(){

    int n,m;
    cin>>n>>m;
    for(i=1; i<=n; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);


    return 0;
}
