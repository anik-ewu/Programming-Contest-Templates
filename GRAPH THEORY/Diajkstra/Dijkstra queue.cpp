///#Dijkstra : Priority_Queue

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N= 1e5;
const ll inf=1e15;

int dis[N];
int par[N];
ll cost[N];
vector < pair< int , int > >adj[N];

int diajkstra(int src, int n){

   priority_queue<pair<int,int> > pq;
   for(int i=1; i<=n; i++)
        cost[i]=inf;

    pq.push(make_pair(0,src));
    cost[src]=dis[src]=0;
    par[src]=-1;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto x: adj[u]){
            int v=x.first;
            int w=x.second;
            if(cost[v]>cost[u]+w){
                dis[v]=(dis[u]*-1)+1;
                cost[v]=w+cost[u];///relaxation
                par[v]=u;
                pq.push(make_pair(dis[v]*-1,v));///to cover the nearest node first
            }
        }
    }
}

int main(){

    int a, b, w, n, m, src;

    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
    }
    cin>>src;
    diajkstra(src, n);
    for(int i=1; i<=n; i++)
        cout<<cost[i]<<endl;

    return 0;
}

/*
input :

4 6
0 1 1
0 2 1
2 3 3
3 4 2
3 0 6
1 3 4
0
output:
Case 1:
4
*/
