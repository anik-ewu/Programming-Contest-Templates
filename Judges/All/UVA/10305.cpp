
#include<bits/stdc++.h>
using namespace std;
#define sf              scanf
#define pf              printf
#define pb              push_back
#define nl              printf("\n")
#define ll              long long int

#define F               first
#define S               second
#define inf             1/0.0
#define PI              2*acos(0.0)
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)

#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))

#define PS              system("pause")
#define MOD             1000000007
#define MX              INT_MAX
#define S              100005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

char f,g;
string s,p;
double aa,bb,cc;
int arr[S],brr[S];
vector< int > v,va,vb;
map< string, int > mp;
int visit[200];
vector < int > adj[200];
int ff;
stack< int > st;

void clear_()
{

    ff=0;
    for(int i=0; i<=101; i++)
        adj[i].clear(),visit[i]=0;

}

void dfs_visit(int u)
{
    int i, v;
    visit[u]=1;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(visit[v]==0)
        {
            visit[v]=1;
            dfs_visit(v);
        }
    }
    visit[u]=2;
    st.push(u);
}

void dfs(int v)
{
    for(int i=1; i<=v; i++)
    {
        if(visit[i]==0)
        {
            dfs_visit(i);
        }
    }
}

int main()
{
    int a,b,c, n,m,t, i,j,k, x,y,z;

    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        for(i=1; i<=n; i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
        }
        dfs(n);
        while(!st.empty())
        {
            if(ff)
                cout<<' ';
            cout<<st.top();
            st.pop();
            ff=1;
        }
        cout<<endl;
        clear_();

    }
    return 0;
}
