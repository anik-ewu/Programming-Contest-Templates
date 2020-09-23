///Euler path of a tree

#include<bits/stdc++.h>
using namespace std;
#define sz 100001

int t;
bool vis[sz];
int st[sz], ed[sz];
vector< int > euler;
vector< int > adj[sz];

void dfs(int u){
    euler.push_back(u);
    vis[u]=1;
    st[u]=++t;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    euler.push_back(u);
    ed[u]=++t;
}

int main(){

    int n, a , b;
    cin>>n;
    for(int i=0; i<n-1; i++){
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);

    }
    dfs(1);
    for(int i=0; i<euler.size(); i++){
        cout<<euler[i]<<' ';
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<st[i]<<' ';
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<ed[i]<<' ';
    }
    cout<<endl;


    return 0;
}
