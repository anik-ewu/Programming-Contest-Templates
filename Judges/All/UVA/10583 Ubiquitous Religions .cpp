#include<bits/stdc++.h>
using namespace std;
#define sz 50005
set < int > st;
int par[sz],Rank[sz];

void Make_Set(int n){
    for(int i=1; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
    }
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(Rank[x]>Rank[y]) par[y]=x;
    else if(Rank[x]<Rank[y]) par[x]=y;
    else par[y]=x,Rank[x]++;
}

int main(){

    int i,j,a,b,t,n,m,cs=1;
    while(cin>>n>>m){
        if(n==0 and m==0)break;
        Make_Set(n);
        for(i=1; i<=m; i++){
            cin>>a>>b;
            if(par[a]!=par[b]){
                Union(a,b);
            }
        }
        for(i=1; i<=n; i++){
            st.insert(find(i));
        }
        cout<<"Case "<<cs++<<": "<<st.size()<<endl;
        st.clear();
    }
    return 0;
}

