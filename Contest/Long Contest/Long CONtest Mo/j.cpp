#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int len;
bool mark[sz];
int St[sz],End[sz];
int fre[sz],ffre[sz];
int color[sz],ans[sz];
vector < int >vec[sz],euler;
struct st{
    int l,r,col,id;
}q[sz];
bool cmp(st a, st b){
    if(a.l/len!=b.l/len)
        return a.l<b.l;
    return a.r<b.r;
}
void dfs(int u){
    euler.push_back(u-1);
    St[u]=euler.size()-1;
    mark[u]=false;
    for(int i=0; i<vec[u].size(); i++){
        int v=vec[u][i];
        if(mark[v])
            dfs(v);
    }
    End[u]=euler.size()-1;
}

void add(int pos){
    fre[color[euler[pos]]]++;
    ffre[fre[color[euler[pos]]]]++;
}
void del(int pos){
    int a=color[euler[pos]];
    int b=fre[a];
    fre[a]--;
    ffre[b]--;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i,j,n,m,a,b;
    cin>>n>>m;
    len=sqrt(n)+1;
    for(i=0; i<n; i++)cin>>color[i];
    for(i=1; i<n; i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    memset(mark,true,sizeof(mark));
    dfs(1);
    for(i=0; i<m; i++){
        cin>>a>>b;
        q[i].l=St[a];
        q[i].r=End[a];
        q[i].col=b;
        q[i].id=i;
    }
    sort(q,q+m,cmp);

    int l=0,  r=-1;
    for(i=0; i<m; i++){
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(l<q[i].l)del(l++);
        while(r>q[i].r)del(r--);
        ans[q[i].id]=ffre[q[i].col];
    }
    for(i=0; i<m; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
