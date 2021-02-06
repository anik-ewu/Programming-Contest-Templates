///Disjoint Set Union : Rank + Path Compression
///Rank               : minimize the depth
///Complexity         : O(log(m))

#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int par[sz],rank[sz];
void Make_Set(int n){
    for(int i=1; i<=n; i++){
        par[i]=i;
        rank[i]=0;
    }
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(rank[x]>rank[y]) par[y]=x;
    else if(rank[x]<rank[y]) par[x]=y;
    else par[y]=x,rank[x]+=1;
}
int main(){
    int i,j,n,m,a,b;
    cin>>n>>m;
    Make_Set(n);
    for(i=1; i<=m; i++){
        cin>>a>>b;
        if(par[find(a)]!=par[find(b)]){
            Union(a,b);
        }
    }
    return 0;
}
/*
Sample Input :
7 6
1 2
1 3
4 5
6 7
5 6
3 7
*/
