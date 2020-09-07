#include<bits/stdc++.h>
using namespace std;
#define S 100005
int colour[S];
vector < int > va[S];
void dfs_visit(int u)
{
    colour[u]=1;
    for(int i=0; i<va[u].size(); i++)
    {
        int v=va[u][i];
        if(colour[v]==0)
        {
            colour[v]=1;
            dfs_visit(v);
        }
    }
    colour[u]=2;
}

int  DFS(int v)
{

    int i,x=0;
    for(i=1; i<=v; i++)
        colour[i]=0;

    for(i=1; i<=v; i++)
    {
        if(colour[i]==0)
        {
            dfs_visit(i);
            x++;
        }
    }
    return x;
}

int main()
{

    ofstream out;
    out.open("lib.txt");
    int a,b,i,j,n,vertex,edge,k=1,s,q,l,r,m;
    long long int x,y,z,ans;
    cin>>q;
    while(q--)
    {
        cin>>n>>m>>l>>r;
        for(i=1; i<=n; i++)
            va[i].clear();
        for(i=1; i<=m; i++)
        {
            cin>>a>>b;
            va[a].push_back(b);
            va[b].push_back(a);
        }
        x=DFS(n);
        if(r>=l)
            ans=n*l;
        else
        {
            y=x*l;
            z=(n-x)*r;
            ans=y+z;
        }
        cout<<ans<<endl;

    }

    return 0;
}

