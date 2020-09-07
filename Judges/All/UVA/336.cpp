#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,adj[100005];
int vis[10000005],d[1000005];
int x;
void bfs(int s, int t)
{
    memset(vis,0,sizeof(d));
    memset(d,1000000,sizeof(d));
    d[s]=0;
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0; i<adj[v].size(); i++)
        {
            int u=adj[v][i];
            if(vis[u]==0)
            {
                q.push(u);
                d[u]=d[v]+1;
                if(d[u]<=t)
                    x++;
                vis[u]=1;
            }
        }
    }
}

int main()
{
    int a,b,c,  n,m,t, l,r, i,j,k,  y=1,z=0;
    while(cin>>n)
    {
        if(n==0)
            break;
        mi.clear();
        while(n--)
        {
            cin>>a>>b;
            if(mi[a]==0)
            {
                v.push_back(a);
                mi[a]=1;
            }

            if(mi[b]==0)
            {
                v.push_back(b);
                mi[b]=1;
            }
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        while(cin>>a>>b)
        {
            if(a==0 && b==0)
                break;
            x=1;
            bfs(a,b);
            z=v.size()-x;
            cout<<"Case "<<y++<<": "<<z<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
        }
        for(i=0; i<v.size(); i++)
            adj[v[i]].clear();
        v.clear();
    }
    return 0;
}
/*
16
1 2  2 7  1 3  3 4  3 5  5 10  5 11
4 6  7 6  7 8  7 9  8 9  8  6  6 11 21 22 22 23
1 1  1 2  3 2  3 3  21 1 0 0

1
1 3
2 0
0 0

1
1 1
1 0
0 0

4
1 2 2 3 4 5 5 6
1 5 1 1 4 2 0 0

4
1 2
2 3
3 4
1 4
1 1
1 2
1 3
1 0
0 0


5
1 2 2 3 3 1 4 5 6 2147483647
1 1 1 0 4 1 4 2 5 1 6 2 8 2 0 0

10
1 2 1 3 3 5 2 5 3 4 5 4 6 4 7 10 10 9 8 9
2 3 7 2 10 1 0 0

4
0 0 1 2 2 3 4 4
1 0 1 1 1 2 1 3 1 4 2 0 2 1 2 2 2 3 2 4 3 0 3 1 3 2 3 3 4 0 4 1 4 2
0 0

30
1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 0 0 1
11 12 12 13 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20 1
21 22 22 23 23 24 24 25 25 26 26 27 27 28 28 29 29 30 30 1
1 0 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 11 1 12 1 13 1 14 1 15 1 16
1 17 1 18 1 19 1 20 1 21 18 0 18 1 18 2 18 3 18 4 18 5 18 6 18 7 18 8 18 9
18 10 18 11 18 12 18 13 18 14 18 15 0 0
32
1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 0 0 1 5 14 24 13
11 12 12 13 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20 1
21 22 22 23 23 24 24 25 25 26 26 27 27 28 28 29 29 30 30 1
1 0 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 11 1 12 1 13 1 14 1 15 1 16
1 17 1 18 1 19 1 20 1 21 18 0 18 1 18 2 18 3 18 4 18 5 18 6 18 7 18 8 18 9
18 10 18 11 18 12 18 13 18 14 18 15 0 0
3
1 2 2 3 4 5
1 0 1 1 1 2 1 3 2 0 2 1 2 2 2 3 3 0 3 1 3 2 3 3 4 0 4 1 4 2 4 3 5 0 5 1 5 2 5 3
0 0

1
10 11
10 0 10 1 10 2 12 1 10 0 10 1 10 2 0 0
0
*/
