#include<bits/stdc++.h>
using namespace std;

int main()
{
    char d;
    bool flag;
    char S[100],D[2];
    int pre[100][100]={};
    int i,x,y,n,m;
    cin>>n>>m;
    while(scanf("%d%d%s",&x,&y,D)==3)
    {
        scanf("%s",S);
        d=D[0];
        flag=true;
        for(i=0; S[i]; i++)
        {
            if(S[i]=='F')
            {
                if(d=='E')
                    x++;
                if(d=='W')
                    x--;
                if(d=='N')
                    y++;
                if(d=='S')
                    y--;
            }
            else
            {
                if(S[i]=='R')
                {
                    if(d=='E')
                        d='S';
                    else if(d=='S')
                        d='W';
                    else if(d=='W')
                        d='N';
                    else if(d=='N')
                        d='E';
                }
                else
                {
                    if(d=='E')
                        d='N';
                    else if(d=='S')
                        d='E';
                    else if(d=='W')
                        d='S';
                    else if(d=='N')
                        d='W';
                }
            }
            if(x<0 || x>n || y<0 || y>m)
            {
                if(d=='E')
                    x--;
                if(d=='W')
                    x++;
                if(d=='N')
                    y--;
                if(d=='S')
                    y++;

                if(pre[x][y]==1)
                    continue;
                flag=false;
                pre[x][y]=1;
                break;
            }
            //cout<<x<<' '<<y<<' '<<d<<endl;
        }
        if(flag)
            printf("%d %d %c\n",x,y,d);
        else
            printf("%d %d %c LOST\n",x,y,d);

    }
    return 0;
}
