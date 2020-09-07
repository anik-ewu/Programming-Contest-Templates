#include<bits/stdc++.h>
using namespace std;
char grid[10][10];
char s[10] = "@IEHOVA#";
int n,m,p[100];

void dfs(int x, int y, int l)
{
    if(x<1 || y<1 || x>n || y>m)
        return ;
    if(grid[x][y]!=s[l])
        return ;
    if(grid[x][y]=='#')
    {
        for(int i=0; i<l; i++)
        {
            if(i)
                cout<<' ';
            if(p[i]==0)
                printf("forth");
            else if(p[i] == 2)
                printf("right");
            else
                printf("left");
        }
    }
    p[l]=0;
    dfs(x-1, y, l+1);
    p[l]=1;
    dfs(x, y-1, l+1);
    p[l]=2;
    dfs(x, y+1, l+1);
}

int main()
{

    int t,i,j,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x,y,0);
        cout<<endl;
    }
    return 0;
}
