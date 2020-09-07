#include<bits/stdc++.h>
using namespace std;
vector < int > edge[500];
int color [500],taken[500];

int Bfs(int n, int src )
{
    queue < int > q;
    for(int i=0; i<n; i++)
        color[i]=false,taken[i]=false;

    q.push(src);

    while(!q.empty())
    {
        int v= q.front();
        q.pop();
        for(int i=0; i<edge[v].size(); i++)
        {
            int u=edge[v][i];
            if(taken[u]==false)
            {
                color[u]=!color[v];
                taken[u]=true;
                q.push(u);
            }
            else if(color[u]==color[v])
            {
                cout<<"NOT BICOLORABLE."<<endl;
                return 0;

            }
        }

    }
    cout<<"BICOLORABLE."<<endl;
    return 0;

}


int main()
{
    int n,i,j,a,b,x,y;

    while(cin>>n)
    {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            edge[i].clear();
        cin>>a;
        for(i=1; i<=a; i++)
        {
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        Bfs(n,0);
    }
    return 0;
}
/*
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
*/
