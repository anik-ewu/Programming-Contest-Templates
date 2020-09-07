///Date     : 18.8.2020
///Approach : Bridge Tree
///Idea     : Make a bridge tree of the graph and set a node between the diameter of the tree

#include<bits/stdc++.h>
using namespace std;
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sz              100005

int t;
bool vis[sz];
vector< int >adj[sz];
map < int , int > mp;
vector< int >Tree[sz];
int d[sz],p[sz],low[sz];
vector< pair< int , int > >links;
map< pair< int , int >, int  >bridge;

///DFS from finding bridges
void dfs(int u){
    vis[u]=1;
    d[u]=low[u]=++t;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            p[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>d[u]){
                bridge[{u,v}]=1;
                bridge[{v,u}]=1;
                links.push_back({u,v});///bridge
            }
        }
        else if(v!=p[u]){
            low[u]=min(low[u],d[v]);
        }
    }
}

///DFS for turning bridge less component into a single node
void dfs2(int u, int node){
    vis[u]=1;
    mp[u]=node;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(bridge[{u,v}])
            continue;
        if(vis[v]==0){
            dfs2(v,node);
        }
    }
}

int bfs(int s, int n){
    queue< int > q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<Tree[u].size(); i++){
            int v=Tree[u][i];
            if(d[v]==-1){
                q.push(v);
                d[v]=d[u]+1;
            }
        }
    }
    int root=1;
    int mx=d[1];
    for(int i=1; i<=n; i++){
        if(d[i]>mx){
            root=i;
            mx=d[i];
        }
    }
    return root;
}

int bfs2(int s, int n){
    queue< int > q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<Tree[u].size(); i++){
            int v=Tree[u][i];
            if(d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    int mx=d[1];
    for(int i=1; i<=n; i++){
        mx=max(mx,d[i]);
    }
    return mx;
}

int solve(int n){

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            t=0;
            dfs(i);///save bridges
        }
    }

    int node=0;
    mp.clear();
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            node++;
            dfs2(i,node);///Turn Component into a node
        }
    }
    ///Build Bridge Tree

    for(int i=1; i<=node; i++)
        Tree[i].clear();

    for(int i=0; i<links.size(); i++){
        int a=mp[links[i].first];
        int b=mp[links[i].second];
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    int tot=links.size(); ///all the bridges

    memset(d,-1,sizeof(d));
    int root=bfs(1,node);

    memset(d,-1,sizeof(d));
    int ans=tot-bfs2(root,node);/// subtracting the bridges
    return ans;
}

void reset(int n){
    links.clear();
    bridge.clear();
    for(int i=1; i<=n; i++){
        p[i]=-1;
        adj[i].clear();
        d[i]=low[i]=vis[i]=0;
    }
}

int main(){
    Fast;///using Fast I/O
    int u,v,i,t,n,m,cs=1;

    cin>>t;
    while(t--){
        cin>>n>>m;
        reset(n);
        for(i=1; i<=m; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<solve(n)<<endl;
    }
    return 0;
}

