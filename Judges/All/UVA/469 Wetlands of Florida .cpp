#include<bits/stdc++.h>
using namespace std;
#define sf              scanf
#define pf              printf
#define nl              printf("\row")
#define F               first
#define S               second

int row,col;
string s[200],p;
int color[200][200];
int dx[]= {1,-1,0,0,1,1,-1,-1};
int dy[]= {0,0,1,-1,1,-1,1,-1};

int bfs(int x, int y)
{
    queue< pair < int, int > > q;
    q.push(make_pair(x,y));
    color[x][y-1]=1;
    int co=1;

    while(!q.empty())
    {
        int i=q.front().F;
        int j=q.front().S;
        q.pop();

        for(int k=0; k<8; k++)
        {
            int c=dx[k]+i;
            int r=dy[k]+j;

            if(c<col && c>0 && r<=row && r>0)
            {
                if(color[c][r-1]==0 && s[c][r-1]=='W')
                {
                    color[c][r-1]=1;
                    q.push(make_pair(c,r));
                    co++;
                }
            }
        }
    }
    return co;
}

int main()
{
    int index,x,y,t,i,a,b,ans,n;
    cin>>t;
    n=t;
    t++;
    getchar();
    while(t--)
    {
        i=1;
        while(getline(cin,p))
        {
            if(p.size()==0)
                break;
            if(p[0]!='W' and p[0]!='L')
            {
                memset(color,0,sizeof(color));
                sscanf(p.c_str(),"%d %d",&a, &b);
                col=i;
                row=s[1].size();
                cout<<bfs(a,b)<<endl;
            }
            else
            {
                s[i++]=p;
            }
        }
        if(t and n!=t)
            cout<<endl;
    }
    return 0;
}

