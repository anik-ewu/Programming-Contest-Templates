///#Dijkstra : Priority_Queue

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define inf 1e18

int dis[sz],cost[sz];
vector <int>adj[sz],weight[sz];

int diajkstra(int src){

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,src));
    cost[src]=dis[src]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            if(cost[v]>cost[u]+weight[u][i]){
                dis[v]=dis[u]+1;
                cost[v]=weight[u][i]+cost[u];///relaxation
                pq.push(make_pair(dis[v]*-1,v));///to cover the nearest node first
            }
        }
    }
}

void init(int vertex){

   for(int i=0; i<=vertex; i++)
    cost[i]=inf,dis[i]=0,adj[i].clear(),weight[i].clear();
}

int main(){

    int i,a,b,c,n,m,p,q;

    scanf("%d%d",&n,&m);
    init(n);///reset
    for(i=1; i<=m; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[b].push_back(a);
        adj[a].push_back(b);
        weight[a].push_back(c);
        weight[b].push_back(c);
    }
    scanf("%d",&p);
    scanf("%d",&q);
    diajkstra(p);///source value

    printf("%d",cost[q]);


    return 0;
}

/*
input :
1
4 4
1 2 2
1 3 5
2 3 1
3 4 3
1
output:
Case 1:
4
*/
