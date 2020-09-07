///Kosaraju algorithm for finding SCC
/*Call DFS(G) to compute finishing times f[u] for each vertex u.
Compute Transpose(G)
Call DFS(Transpose(G)), but in the main loop of DFS, consider the vertices in order of decreasing f[u] (as computed in step 1)
Output the vertices of each tree in the depth-first forest of step 3 as a separate strong connected component.
*/

#include<bits/stdc++.h>
using namespace std;
#define sz              1005

int t;
int f[sz];
int vis[sz];
vector< int > adj[sz];
map < string, int > mp;
vector< int > Trans[sz];

struct st{
    int x, y;
}arr[sz];

void reset(int n){
    t=0;
    mp.clear();
    for(int i=0; i<=n; i++){
        adj[i].clear();
        Trans[i].clear();
        f[i]=vis[i]=0;
    }
}

bool cmp(st a, st b){
    return (a.x>=b.x);
}

void dfs(int u, int par){
    t++;
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(v==u)continue;
        if(vis[v]==0){
            dfs(v,u);
        }
    }
    f[u]=t++;
}

void dfs_2(int u){

    vis[u]=1;
    for(int i=0; i<Trans[u].size(); i++){
        int v=Trans[u][i];
        if(vis[v]==0){
            dfs_2(v);
        }
    }
}

int count_scc(int n){

    int t=0;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(i,0);
        }
    }
    for(int i=1; i<=n; i++){
        arr[i].x=f[i];
        arr[i].y=i;
    }
    sort(arr+1,arr+n+1,cmp);
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n ; i++){
        if(vis[arr[i].y]==0){
           dfs_2(arr[i].y);
           cnt++;
        }
    }
    return cnt;
}

int main(){

    int n, m, t, a, b, c;

    while(cin>>n>>m){
        if(n==0 && m==0)break;
        reset(n);
        for(int i=1; i<=m; i++){
            cin>>a>>b>>c;
            if(c==1){
                adj[a].push_back(b);
                Trans[b].push_back(a);
            }
            else{
                adj[a].push_back(b);
                adj[b].push_back(a);
                Trans[a].push_back(b);
                Trans[b].push_back(a);
            }
        }
        cout<<count_scc()
    }

    return 0;
}
