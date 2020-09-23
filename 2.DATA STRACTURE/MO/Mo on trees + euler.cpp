///Mo's on three
///Cf: 375 D
#include<bits/stdc++.h>
using namespace std;
#define sz 100005
const int len=320;

int col[sz];
bool vis[sz];
int ans[sz];
int st[sz], ed[sz];
int fre[sz], ffre[sz];
vector < int > adj[sz], euler;

struct query{
    int l, r, k, id;
}q[sz];

bool cmp(query &a, query &b){
    if(a.l/len!=b.l/len)
        return a.l/len<b.l/len;
    return (a.l/len & 1) ? a.r<b.r : a.r>b.r;///time optimization
}

void add(int pos){
    fre[col[euler[pos]]]++;
    ffre[fre[col[euler[pos]]]]++;
}

void del(int pos){
    ffre[fre[col[euler[pos]]]]--;
    fre[col[euler[pos]]]--;
}


void dfs(int u){
    euler.push_back(u-1);
    st[u]=euler.size()-1;
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    ed[u]=euler.size()-1;
}

int main(){

    int i, n, m, a, b;
    cin>>n>>m;
    for(i=0; i<n; i++){
        cin>>col[i];
    }
    for(i=0; i<n-1; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);

    for(i=0; i<m; i++){
        cin>>a>>b;
        q[i].l=st[a];
        q[i].r=ed[a];
        q[i].k=b;
        q[i].id=i;
    }
    sort(q+0, q+m, cmp);

    int l=0, r=-1;
    for(i=0; i<m; i++){
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(l<q[i].l)del(l++);
        while(r>q[i].r)del(r--);
        ans[q[i].id]=ffre[q[i].k];
    }
    for(i=0; i<m; i++){
        cout<<ans[i]<<endl;
    }


    return 0;
}
