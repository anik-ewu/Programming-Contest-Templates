/*
Date    : 27 April 2021
Author  : Sabbir Hasan Anik
Algo    : Bellman ford [to detect negative cycle]
Idea    : Run bellman ford from a source and update all possible nodes |V|-1 times. Here |V| =total vertex
          Then again try to update all possible node |V| times, If any nodes gets update there will be negative
          weight cycle.
Notes   : To find which nodes are in the cycle, we can put nodes in a queue and, simply make a
          search on the graph.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
ll dis[N];
vector< pair< int , int > > adj[N];


bool bellmanford(int s, int n){

    for(int i=1; i<=n; i++)
        dis[i]=INT_MAX;

    dis[s]=0;
    for(int k=1; k<n; k++){
        for(int i=1; i<=n; i++){
            for(auto x: adj[i]){
                int v=x.first;
                int w=x.second;
                int y=w+dis[i];
                if(dis[v]>y){
                    dis[v]=y;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(auto x: adj[i]){
            int v=x.first;
            int w=x.second;
            int y=w+dis[i];
            if(dis[v]>y){
                return true; ///cycle exists
            }
        }
    }
    return false;///no cycle
}

int main(){

    int n, m, a, b, w;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});///for bidirectional
    }
    bool cycle=bellmanford(1, n);///passing source and the vertex no to function

    if(cycle==true){
        cout<<"Cycle exist"<<endl;
    }
    else{
        cout<<"NO cycle "<<endl;
    }

    return 0;
}
