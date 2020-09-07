#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int con;
int colour[100005];
vector < int > adj[100005];

void dfs_visit(int u)
{
    con++;
    int i,v;
    colour[u]=1;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(colour[v]==0)
        {
            colour[v]=1;
            dfs_visit(v);
        }
    }
}
long long int  DFS(int v)
{

    long long int i,x=0,y=0,sum=0,res=0,a,b;
    for(i=0; i<=v; i++)
        colour[i]=0;
    for(i=0; i<v; i++)
    {
        if(colour[i]==0)
        {
            con=0;
            dfs_visit(i);
            res=res+(sum*con);
            sum+=con;
        }
    }
    return res;
}

int main()
{

    int a,b,i,j,n,vertex,edge,k=1,s;
    cin>>vertex>>edge;
    for(i=1; i<=edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    cout<<DFS(vertex)<<endl;
    return 0;
}



