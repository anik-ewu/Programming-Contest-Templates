#include<bits/stdc++.h>
using namespace std;

#define sz 20005

int out[sz];
bool vis[sz];
vector< int > adj[sz];

int solve(int n){

    int res=0;

    for(int i=1; i<=n; i++){
        if(out[i]==0)res++;
    }
    return res;
}

int main(){

    int t, u, v, i, n, m, cs=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            adj[i].clear();
            out[i]=0;
        }
        for(i=1; i<=m; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            out[u]++;
        }
        cout<<"Case "<<cs++<<": "<<solve(n)<<endl;
    }

    return 0;
}
