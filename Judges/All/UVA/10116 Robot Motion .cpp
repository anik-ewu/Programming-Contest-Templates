#include<bits/stdc++.h>
using namespace std;
char arr[100][100];
int cost[100][100];

void bfs(int n, int m, int k)
{
    int c=0,x,y;
    cost[1][k]=c;
    x=1;
    y=k;
    while(true)
    {
        if(arr[x][y]=='S')
            x++;
        else if(arr[x][y]=='N')
            x--;

        else if(arr[x][y]=='E')
            y++;

        else if(arr[x][y]=='W')
            y--;
        c++;
        if(x<1 || y<1 || x>n || y>m)
        {
            cout<<c<<" step(s) to exit"<<endl;
            return;
        }
        else if(cost[x][y]!=0 || (x==1 and y==k))
        {
            cout<<cost[x][y]<<" step(s) before a loop of "<<c-cost[x][y]<<" step(s)"<<endl;
            return;
        }
        cost[x][y]=c;
    }
}
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        if(n==0 and m==0 and k==0)
            break;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>arr[i][j];
            }
        }
        bfs(n,m,k);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cost[i][j]=0;
            }
        }
    }
    return 0;
}
