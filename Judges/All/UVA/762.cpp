#include<bits/stdc++.h>
using namespace std;
string s, p;
int par[500000];
vector < int > v;
bool visited[500000];
map < string, int > mp;
vector < int > adj[500000];
map < int, string   > mps;
bool bfs(int src, int des)
{
    queue< int > q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int vv=adj[u][i];
            if(visited[vv]==false)
            {
                q.push(vv);
                par[vv]=u;
                if(vv==des)
                    return true;
                visited[vv]=true;
            }
        }
    }
    return false;
}
void init(int n)
{
    for(int j=1; j<=n+n; j++)
        adj[j].clear(),visited[j]=false;
    mp.clear();
    mps.clear();
    v.clear();
}

void printpath(int  a, int b)
{
    if(a==b)
    {
        return;
    }
    printpath(par[a],b);
    cout<<mps[par[a]]<<" "<<mps[a]<<endl;
}
int main()
{

    int t,n,node,x,y,cs=0;
    while(cin>>n)
    {
        node=1;
        init(n);
        getchar();
        for(int j=1; j<=n; j++)
        {
            cin>>s>>p;
            if(mp[s]==0)
            {
                mp[s]=node;
                mps[node]=s;
                node++;
            }
            if(mp[p]==0)
            {
                mp[p]=node;
                mps[node]=p;
                node++;
            }
            x=mp[s];
            y=mp[p];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cin>>s>>p;
        x=mp[s];
        y=mp[p];
        if(cs)
            cout<<endl;
        if(bfs(x,y))
        {
            printpath(y,x);
        }
        else
        {
            cout<<"No route"<<endl;
        }
        cs=1;
    }
    return 0;
}
