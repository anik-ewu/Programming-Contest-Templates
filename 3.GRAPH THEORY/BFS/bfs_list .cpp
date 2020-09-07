///GRAPH      :BFS [ List ]
///Complexity :O(v+e)

#include<bits/stdc++.h>
using namespace std;
#define sz 100005
vector < int > adj[sz+5];
int color[sz+5],dist[sz+5],par[sz+5];

void init(int node){
    for(int i=0; i<=node; i++){
        par[i]=-1, color[i]=0, dist[i]=INT_MAX;
        adj[i].clear();
    }
}

void bfs(int s)
{
    queue<int > q;
    q.push(s), par[s]=0, dist[s]=0, color[s]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            if(color[v]==0){
                par[v]=u;
                q.push(v);///new element
                color[v]=1;
                dist[v]=dist[u]+1;
            }
        }
        color[u]=2;
    }
}

int main()
{

    int a,b,i,vertex,edge,source;
    cin>>vertex>>edge;

    init(vertex);///reset

    for(i=1; i<=edge; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);///undirected
    }
    bfs(0);

    return 0;
}
