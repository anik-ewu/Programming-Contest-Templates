#include<bits/stdc++.h>
using namespace std;
char d;
int x, y;
string s;
int mat[100][100];
void init(int n, int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            mat[i][j]=0;
    }
}

void traverse()
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='Q')
            return ;
        if(s[i]=='F')
        {
            if(d=='E')
                y++;
            else if(d=='W')
                y--;
            else if(d=='N')
                x--;
            else if(d=='S')
                x++;
        }
        else
        {
            if(s[i]=='R')
            {
                if(d=='E')
                    d='S';
                else if(d=='W')
                    d='N';
                else if(d=='N')
                    d='E';
                else if(d=='S')
                    d='W';
            }
            else if(s[i]=='L')
            {
                if(d=='E')
                    d='N';
                else if(d=='W')
                    d='S';
                else if(d=='N')
                    d='W';
                else if(d=='S')
                    d='E';
            }
        }
        if(mat[x][y]==0)
        {
            if(d=='E')
                y--;
            else if(d=='W')
                y++;
            else if(d=='N')
                x++;
            else if(d=='S')
                x--;
        }
    }
}
int main()
{
    int t,n,m,i,j,k,cs=0;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n>>m;
        getchar();
        init(n,m);
        for(j=1; j<=n; j++)
        {
            getline(cin,s);
            for(k=0; k<m; k++)
            {
                if(k>=s.size() || s[k]!='*')
                    mat[j][k+1]=1;
            }
        }
        cin>>x>>y;
        d='N';
        while(getline(cin,s))
        {
            traverse();
            if(s[s.size()-1]=='Q')
                break;
        }
        if(cs)
            cout<<endl;
        cout<<x<<' '<<y<<' '<<d<<endl;
        cs=1;
    }
    return 0;
}

