///Topsort using bfs + indegree
#include<bits/stdc++.h>
using namespace std;

#define sz 101

bool vis[sz];
int indeg[sz];
vector< int > adj[sz];

void solve(int n){

    queue< int > q;
    vector< int > ans;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0)q.push(i),vis[i]=1;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            indeg[v]--;
            if(indeg[v]==0 and vis[v]==0){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    for(int i=0; i<ans.size(); i++){
        if(i)cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){

    int n, m;
    while(cin>>n>>m){
        if(n==0 && m==0)break;

        for(int i=1; i<=n; i++){
            adj[i].clear();
            indeg[i]=vis[i]=0;
        }

        int a, b;
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            indeg[b]++;
        }
        solve(n);
    }

    return 0;
}
