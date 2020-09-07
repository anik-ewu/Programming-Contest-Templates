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
string s[200],p;
double aa,bb,cc;
int arr[Sz],brr[Sz];
vector< int > v,va,vb;
map< int, int > mp;

int dx[]= {1,-1,0,0,1,1,-1,-1};
int dy[]= {0,0,1,-1,1,-1,1,-1};

vector < int > adj[200];
int color[200][200];
int n,m,count;

void bfs(int x, int y)
{
    queue< pair < int, int > > q;
    q.push(make_pair(x,y));
    color[x][y]=1;

    while(!q.empty())
    {
        int i=q.front().F;
        int j=q.front().S;
        q.pop();

        for(int k=0; k<8; k++)
        {
            int xx=dx[k]+i;
            int yy=dy[k]+j;

            if(xx<m && xx>=0 && yy<n && yy>=0 && color[xx][yy]==0 && s[xx][yy]=='@')
            {
                color[xx][yy]=1;
                q.push(make_pair(xx,yy));
                //cout<<xx<<' '<<yy<<endl;
            }
        }
    }
    //cout<<endl;
}

int main()
{
    int a,b,c, t, i,j,k, x,y,z;
    while(cin>>m)
    {
        if(m==0)
            break;
        cin>>n;
        for(i=0; i<m; i++)
            cin>>s[i];
        x=0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                if(color[i][j]==0 && s[i][j]=='@')
                {
                    x++;
                    bfs(i,j);
                }
        }
        cout<<x<<endl;
        memset(color,0,sizeof(color));
    }

    return 0;
}

