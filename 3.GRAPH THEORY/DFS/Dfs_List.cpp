
/// DFS : List

int colour[100],p[100],d[100],f[100],time=0;
vector < int > adj[100];
void dfs_visit(int u)
{
    int i,v;
    colour[u]=1;
    time++;
    d[u]=time;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(colour[v]==0)
        {
            colour[v]=1;
            p[v]=u;
            dfs_visit(v);
        }
    }
    time++;
    f[u]=time;
    colour[u]=2;
}
int  DFS(int v)
{
    int time=x=0;
    for(int i=1; i<=v; i++)
    {
        if(colour[i]==0)
        {
            dfs_visit(i);
            x++;///count forest
        }
    }
}


