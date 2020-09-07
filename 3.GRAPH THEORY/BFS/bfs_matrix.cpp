///GRAPH      :BFS [ Matrix ]
///Complexity :O(v+e)

#include<bits/stdc++.h>
using namespace std;
#define sz 10005
int adj[sz+5][sz+5];
int color[sz+5],dist[sz+5],par[sz+5];

void init(int node){
    memset(adj,0,sizeof(adj));
    for(int i=0; i<=node; i++){
        par[i]=-1, color[i]=0, dist[i]=INT_MAX;
    }
}

void bfs(int s, int node)
{
    queue<int > q;
    q.push(s), par[s]=0, dist[s]=0, color[s]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0; i<node; i++){
            if(adj[u][i] and color[i]==0){
                par[i]=u;
                q.push(i);///new element
                color[i]=1;
                dist[i]=dist[u]+1;
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
        adj[a][b]=1;
        adj[b][a]=1;///undirected
    }
    bfs(0,vertex);

    return 0;
}
