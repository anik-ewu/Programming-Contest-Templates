#include<bits/stdc++.h>
using namespace std;
#define sf              scanf
#define pf              printf
#define pb              push_back
#define nl              printf("\n")
#define ll              long long int
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define MOD             1000000007
#define MX              INT_MAX
#define Sz              1005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

string s;
bool flag;
char f,g;
int colour[Sz],mark[Sz];
vector < int > adj[Sz],vv;
void dfs_visit(int node, int u)
{
    if(u==node)
    {
        flag=true; /// reached destination
        return ;
    }
    int i,v;
    colour[u]=1;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(colour[v]==0)
        {
            colour[v]=1;
            dfs_visit(node,v);
        }
    }
}

int main()
{
    int t,a,b,c, n,m,k, i,j, x,y,z,sum=0;
    ofstream out("in.txt");
    sf("%d",&t);
    for(j=1; j<=t; j++)
    {
        sf("%d",&n);
        x=0;
        y=0;
        getchar();
        while(true)
        {
            if(!getline(cin,s) || s.empty())
                break;
            sscanf(s.c_str(),"%c %d %d",&f,&a,&b);
            if(f=='c')
            {
                adj[a].pb(b);
                adj[b].pb(a);
            }
            else
            {

                memset(colour,0,sizeof(colour));
                flag=false; /// marking as false
                dfs_visit(b,a);
                if(flag)
                {
                    x++;   /// reached source to destination
                }
                else
                    y++;
            }
        }
        if(j>1)
        {
            cout<<endl;
        }
        cout<<x<<','<<y<<endl;
        for(i=1; i<=n; i++)
            adj[i].clear();

    }

    return 0;
}

