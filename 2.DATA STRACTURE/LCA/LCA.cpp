///LCA : Using Sparse Table

#include<bits/stdc++.h>
using namespace std;
#define sz 10001
int lavel[sz];
int parent[sz];
int table[sz][25];
vector < int > adj[sz];
void dfs(int from, int u, int lv){
    lavel[u]=lv;
    parent[u]=from;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(v==from)continue;
        dfs(u, v, lv+1);
    }
}

void init(int n){

    memset(table, -1, sizeof(table));
    for(int i=0; i<n; i++){
        table[i][0]=parent[i];
    }
    for(int j=1; (1<<j)<n; j++){
        for(int i=0; i<n; i++){
            if(table[i][j-1]!=-1){
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }
    }
}

int lca(int a, int b){

    int log=1;
    if(lavel[a]<lavel[b])swap(a,b);
    while((1<<(log+1))>lavel[a])log++; ///calculating max level

    ///making level[a]==level[b]
    for(int i=log; i>=0; i--){
        if(lavel[a]-(1<<i)>=lavel[b])
            a=table[a][i];
    }
    if(a==b)return a;

    for(int i=log; i>=0; i--){
        if(table[a][i]!=-1 && table[a][i]!=table[b][i]){
            a=table[a][i];  b=table[b][i];
        }
    }
    return parent[a];
}

int main(){

    int a,b,t, n, m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(-1 , 0, 0); ///node : 0 to n-1
    init(n);
    cout<<lca(11,14)<<endl;

    return 0;
}
/*
Input:
17 16
0 1
1 2
1 8
2 3
3 4
4 5
5 6
6 7
6 14
8 9
9 10
10 11
11 12
11 15
12 13
12 16

Output:
1
*/
