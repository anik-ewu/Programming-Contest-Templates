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
char f,g;
bool flag;
string s,p;
double aa,bb,cc;
bool arr[Sz][Sz],brr[Sz];
map< pair < int, int >, int > mpi;
map< string, int > mp;
vector< int > v,va,vb,adj[1000];
vector< pair< int, int > > vp;
int color[1000];
void init(int n)
{
    for(int i=0; i<=n; i++)
        adj[i].clear(),color[i]=0;
    v.clear();

}

void bfs(int src)
{
    queue < int > q;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int vv=adj[u][i];
            if(color[vv]==0)
            {
                color[vv]=1;
                q.push(vv);
            }
        }
    }
}

int main()
{
    ofstream out;
    out.open("ver.txt");
    int a,b,c, n,m,t, i,j,k, x,y,z,sum=0;
    while(cin>>n)
    {
        init(n);
        if(n==0)
            break;
        while(cin>>a)
        {
            if(a==0)
                break;
            while(cin>>b)
            {
                if(b==0)
                    break;
                adj[a].pb(b);
            }
        }
        cin>>m;
        for(i=1; i<=m; i++)
        {
            cin>>x;
            bfs(x);
            for(j=1; j<=n; j++)
                if(color[j]==0)
                    v.pb(j);
            cout<<v.size();
            for(j=0; j<v.size(); j++)
            {
                cout<<' '<<v[j];
            }
            cout<<endl;
            for(j=1; j<=n; j++)
                color[j]=0;
            v.clear();
        }
    }

    return 0;
}


