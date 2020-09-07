#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define infinity 1<<30
int dist[sz],arr[sz];
vector < int > adj[sz],w[sz];

int po(int n){
    return n*n*n;
}

void init(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear();
        w[i].clear();
        dis[i]=infinity;
    }
}

int main(){

    int n,m,x,y,i, j, k, t, q;
    while(cin>>n){
        init(n);
        for(i=1; i<=n; i++)
        cin>>arr[i];
        cin>>m;
        for(i=1; i<=m; i++){
            cin>>a>>b;
            x=po(arr[b]-arr[a]);
            w[a].push_back(x);
            w[b].push_back(x);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin>>q;
        while(q--){
            cin>>
        }
    }




    return 0;
}
