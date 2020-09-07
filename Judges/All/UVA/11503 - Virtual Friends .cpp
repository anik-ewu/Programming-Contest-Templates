#include<bits/stdc++.h>
using namespace std;
#define sz 200005
string s,p;
map <string , int > mp;
int par[sz],group[sz],Rank[sz];
void Make_Set(int n){
    n=min(n*2,sz);
    for(int i=1; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
        group[i]=1;
    }
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
int Union(int a, int b, int size){
    int x=find(a);
    int y=find(b);
    int id=x;
    if(x==y)return id;///x & y are in same group, no need to update
    if(Rank[x]>Rank[y])par[y]=x , group[x]+=group[y];
    else if(Rank[x]<Rank[y])par[x]=y , group[y]+=group[x],id=y;
    else par[y]=x,Rank[x]++,group[x]+=group[y];
    return id;
}

int main(){
    int i,j,a,b,t,n,m,cnt,id;
    cin>>t;
    while(t--){
        cin>>n;
        cnt=0;
        mp.clear();
        Make_Set(n);
        for(i=1; i<=n; i++){
            cin>>s>>p;
            if(mp[s]==0)cnt++,mp[s]=cnt;
            if(mp[p]==0)cnt++,mp[p]=cnt;
            a=mp[s];
            b=mp[p];
            if(par[a]!=par[b]){
                id=Union(a,b,cnt);
            }
            else id=find(a);

            cout<<group[id]<<endl;
        }
    }
    return 0;
}
