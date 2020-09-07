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
#define Sz              100005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

char f,g;
string s,p;
double aa,bb,cc;
int arr[Sz],brr[Sz];
vector< int > v,va,vb;
map< string, int > mp;
map < int, string > mps;
int dx[]= {1,-1,0,0,1,1,-1,-1};
int dy[]= {0,0,1,-1,1,-1,1,-1};

vector < int > adj[2000];
int color[2000],par[2000];
int n,m,count;
void print_path(int  a, int b);
void bfs(int x, int y)
{
    queue< int > q;
    q.push(x);
    color[x]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==y)
            return;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(color[v]==0)
            {
                color[v]=1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}

void print_path(int  a, int b)
{
    if(a==b)
    {
        s=mps[a];
        p+=s[0];
        return;
    }
    print_path(par[a],b);
    s=mps[a];
    p+=s[0];
}


int main()
{
    int a,b,c, t, i,j,k, x,y,z,cs=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        x=0;
        for(i=1; i<=n; i++)
        {
            cin>>s>>p;
            if(!mp[s])
            {
                x++;
                mp[s]=x;
                mps[x]=s;
            }
            if(!mp[p])
            {
                x++;
                mp[p]=x;
                mps[x]=p;
            }
            a=mp[s];
            b=mp[p];
            adj[a].pb(b);
            adj[b].pb(a);
        }
        if(cs)
            cout<<endl;
        while(m--)
        {
            memset(color,0,sizeof(color));
            memset(par,0,sizeof(color));
            cin>>s>>p;
            a=mp[s];
            b=mp[p];
            bfs(a,b);
            p="";
            print_path(b,a);
            cout<<p<<endl;
        }
        for(i=0; i<=n*2; i++)
            adj[i].clear();
        mp.clear();
        cs=1;
        mps.clear();
    }
    return 0;
}


