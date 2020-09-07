#include<bits/stdc++.h>
using namespace std;

map < int , int > mp;

int main()
{
    int a,n,m,i,j,t,ans=0;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            mp[a]++;
        }
        for(j=1; j<=m; j++)
        {
            scanf("%d",&a);
            if(mp[a])
            {
                mp[a]--;
                ans+=2;
            }
        }
        printf("%d\n",(n+m)-ans);
        mp.clear();
    }
    return 0;
}
