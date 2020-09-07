///SCC: TARJAN ALGO

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              1005

int t,g;
int vis[sz];
stack < int > st;
int d[sz],low[sz];
vector< int > adj[sz];
map < string, int > mp;

void reset(int n){
    g=t=0;
    mp.clear();
    for(int i=0; i<=n; i++){
        adj[i].clear();
        low[i]=d[i]=vis[i]=0;
    }
    while(!st.empty())st.pop();
}

void dfs(int u, int par){
    vis[u]=1;
    st.push(u);
    d[u]=low[u]=t++;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(v==u)continue;
        if(vis[v]==0){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==1){
            low[u]=min(low[u],d[v]);
        }
    }
    if(low[u]==d[u]){
        g++;
        while(1){
            int k=st.top();
            st.pop();
            low[k]=low[u];
            vis[k]=2;
            if(k==u) break;
        }
    }
}

int count_scc(int n){

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(i,0);
        }
    }
    return g;
}

int main(){
    ///Fast;///using Fast I/O
    string s,p;
    int a,b,c, i,j,k, t,n,m;

    while(cin>>n>>m){
        if(n==0 && m==0)break;
        reset(n);
        getchar();
        for(i=1; i<=n; i++){
            getline(cin,s);
            mp[s]=i;
        }
        for(i=1; i<=m; i++){
            getline(cin,s);
            getline(cin,p);
            a=mp[s];b=mp[p];
            adj[a].push_back(b);
        }

        cout<<count_scc(n)<<endl;
    }
    return 0;
}


