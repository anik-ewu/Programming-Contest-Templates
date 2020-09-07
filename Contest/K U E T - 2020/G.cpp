#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sz 30005
#define inf 1e18
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll par[sz],Rank[sz];
ll dis[sz],cost[sz];
vector < ll > V[sz],W[sz];

void init(int n){
    for(int i=0; i<=n; i++){
        dis[i]=cost[i]=inf;
        V[i].clear();
        W[i].clear();
    }
}

void Make_Set(int n){

    for(int i=0; i<=n; i++)par[i]=i;
    for(int i=0; i<=n; i++)Rank[i]=0;
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);

    if(Rank[x]>Rank[y])par[y]=x;
    else if(Rank[x]<Rank[y])par[x]=y;
    else Rank[x]++, par[y]=x;
}

void diajkstra(int src){
    priority_queue< pair < int , int > >pq;
    pq.push({0,src});
    dis[src]=cost[src]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(int i=0; i<V[u].size(); i++){
            int v=V[u][i];
            if(cost[v]>cost[u]+W[u][i]){
                dis[v]=dis[u]+1;
                cost[v]=cost[u]+W[u][i];
                pq.push({dis[v]*-1,v});
            }
        }
    }
}

int main(){

    fast;
    int q,i,j,n,m,t,a,b,c,cs=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        init(n);
        Make_Set(n);
        for(i=1; i<=m;i++){
            cin>>a>>b>>c;
            if(par[find(a)]!=par[find(b)]){
                Union(a,b);
            }
            W[a].push_back(c);
            W[b].push_back(c);
            V[a].push_back(b);
            V[b].push_back(a);

        }
        ///precal using Diajkstra
        for(i=1; i<=n; i++){
            if(cost[i]==inf){
                diajkstra(find(i));
            }
        }
        cout<<"Case "<<cs++<<":"<<endl;
        cin>>q;
        while(q--){
            cin>>a>>b;
            if(par[find(a)]!=par[find(b)]){
                cout<<-1<<endl;
            }
            else{
                int pr=par[find(a)];
                int x=max(cost[a],cost[b]);
                int y=min(cost[a],cost[b]);
                ///cout<<pr<<' '<<x<<' '<<y<<endl;
                if(pr==a)cout<<cost[b]<<endl;
                else if(pr==b)cout<<cost[a]<<endl;
                else{
                    cout<<x+y<<endl;
                }
            }
        }
    }
    return 0;
}
