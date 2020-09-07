#include<bits/stdc++.h>
using namespace std;
#define Sz 100005

int t;
int vis[Sz],d[Sz],p[Sz],low[Sz];
vector< int > adj[Sz];
pair< int, int > pp;
vector< pair < int, int > > bridge;
void dfs_visit(int u)
{
    int i,j,v;
    vis[u]=1;
    t++;
    d[u]=low[u]=t;

    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(vis[v]==0)
        {
            p[v]=u;
            dfs_visit(v);
            low[u]=min(low[u],low[v]);

            if(low[v]>d[u])
            {
                if(u<v)
                    bridge.push_back(make_pair(u,v));
                else
                    bridge.push_back(make_pair(v,u));

            }
        }
        else if(v!=p[u])
        {
            low[u]=min(low[u],d[v]);
        }
    }
}

void dfs(int n)
{
    for(int i=0; i<n; i++)
    {
        if(vis[i]==0)
        {
            dfs_visit(i);
        }
    }
}

int main()
{
    int a,b,c,n,i,j;
    char f;
    while(cin>>n)
    {
        for(i=0; i<n; i++)
        {
            cin>>a>>f>>b>>f;
            for(j=1; j<=b; j++)
            {
                cin>>c;
                adj[a].push_back(c);
            }
        }
        t=0;
        dfs(n);
        if(bridge.size()==0)
            cout<<"0 critical links"<<endl;
        else
        {
            sort(bridge.begin(),bridge.end());
            cout<<bridge.size()<<" critical links"<<endl;
            for(i=0; i<bridge.size(); i++)
                cout<<bridge[i].first<<' '<<'-'<<' '<<bridge[i].second<<endl;
        }
        cout<<endl;
        for(i=0; i<n; i++)
        {
            vis[i]=0;
            d[i]=0;
            low[i]=0;
            p[i]=0;
            adj[i].clear();
        }
        bridge.clear();

    }

    return 0;
}
