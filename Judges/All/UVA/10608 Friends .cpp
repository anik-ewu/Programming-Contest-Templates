#include<bits/stdc++.h>
using namespace std;
#define sz 30005
int par[sz],arr[sz],rank[sz];

void Make_Set(int n){
    for(int i=1; i<=n; i++){
        par[i]=i;
        rank[i]=arr[i]=0;
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
    else par[y]=x,rank[x]++;
}

int main(){

    int i,j,a,b,t,n,m,cnt;
    cin>>t;
    while(t--){
        cin>>n>>m;
        Make_Set(n);
        for(i=1; i<=m; i++){
            cin>>a>>b;
            if(par[a]!=par[b]){
                Union(a,b);
            }
        }
        for(i=1; i<=n; i++){
            arr[find(i)]++;
        }
        cnt=0;
        for(i=1; i<=n; i++){
            cnt=max(cnt,arr[i]);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
