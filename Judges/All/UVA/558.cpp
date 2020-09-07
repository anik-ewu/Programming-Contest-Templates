#include<bits/stdc++.h>
using namespace std;

#define sz 200005
#define infinity 100000000  //2^30

bool cycle;
int dis[sz+10];
vector <int>adj[sz+10],weight[sz+10];

void init(int n){
    for(int i=0; i<n; i++)
        dis[i]=infinity,adj[i].clear(),weight[i].clear();
}

bool check_cycle(int i){
    for(int j=0; j<adj[i].size(); j++){
        int v=adj[i][j];
        if(dis[v]>dis[i]+weight[i][j]){
            return true;///cycle
        }
    }
    return false;
}

void bellmanford(int s, int n){

    dis[s]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int v=adj[i][j];
            if(dis[v]>dis[i]+weight[i][j]){
                dis[v]=dis[i]+weight[i][j];
            }
        }
    }
    cycle=check_cycle(n);///cycle exists
}

int main(){

    int a,b, c, n, m, i, j, t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        init(n);
        for(i=1; i<=m; i++){
            cin>>a>>b>>c;
            adj[a].push_back(b);
            weight[a].push_back(c);
        }
        bellmanford(0,n-1);
        if(cycle)cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
    return 0;
}
