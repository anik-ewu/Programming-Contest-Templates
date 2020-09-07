#include<bits/stdc++.h>
using namespace std;
#define Sz 1005

int t,root;
string s;
int vis[Sz],d[Sz],p[Sz],low[Sz],point[Sz];
vector< int > adj[Sz];

void dfs_visit(int u)
{
    int i,j,v,child=0;
    vis[u]=1;
    t++;
    d[u]=low[u]=t;

    for(i=0; i<adj[u].size(); i++)
    {
        child++;
        v=adj[u][i];
        if(vis[v]==0)
        {
            p[v]=u;
            dfs_visit(v);
            if(p[u]==0 && child>1)
                point[u]=1;
            low[u]=min(low[u],low[v]);
            if(p[u]!=0 && low[v]>=d[u])
                point[u]=1;

        }
        else if(v!=p[u])
        {
            low[u]=min(low[u],d[v]);
        }
    }
}

void dfs(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
            dfs_visit(i);
    }
}

int main()
{
    int a,b,c,n,i,j,x,cs=1;
    char f;
    while(cin>>n)
    {
        if(n==0)
            break;
        while(cin>>a)
        {
            if(a==0)
                break;
            getline(cin,s);
            for(i=1; i<s.size(); i++)
            {
                if(s[i]==' ')
                    continue;
                x=s[i]-'0';
                i++;
                if(i==s.size() || s[i]==' ')
                {
                    adj[a].push_back(x);
                    adj[x].push_back(a);
                    continue;
                }
                x*=10;
                x+=(s[i]-'0');
                adj[a].push_back(x);
                adj[x].push_back(a);
            }
        }
        t=0;
        dfs(n);

        x=0;
        for(i=1; i<=n; i++)
            if(point[i]==1)
                x++;
        cout<<x<<endl;

        ///clear
        for(i=0; i<=n; i++)
        {
            vis[i]=0;
            d[i]=0;
            low[i]=0;
            p[i]=0;
            point[i]=0;
            adj[i].clear();
        }
    }

    return 0;
}

