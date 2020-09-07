#include<bits/stdc++.h>
using namespace std;
int adj[150][150],color[200];

int x, y;
vector < int > v;
void dfs_visit(int u, int v)
{
    int i;
    color[u]=1;
    x++;
    for( i=1; i<=v; i++)
    {
        if(color[i]==0 && adj[u][i]==1)
        {
            color[i]=1;
            dfs_visit(i,v);
        }

    }
}

void dfs(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
        color[i]=0;
    for(i=1; i<=n; i++)
    {
        if(color[i]==0)
        {
            x=0;
           dfs_visit(i,n);
            v.push_back(x);
            cout<<x<<endl;
        }
    }
}

int main()
{
    int n,m,b,a,i;
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    dfs(n);
    for(i=0; i<v.size(); i++)
    {
        if(v[i]==1)
            x++;
        else if(v[i]>2)
            y+=v[i]-2;
    }
    cout<<y<<endl;
    return 0;


}
