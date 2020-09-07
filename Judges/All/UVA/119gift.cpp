#include<bits/stdc++.h>
using namespace std;
int f[150];

int main()
{
    int n,i,j,k,x,y,z,l,r;
    char a[150][50],b[150],c[150];
    while(cin>>n)
    {
        for(i=1; i<=n; i++)
            cin>>a[i];

        for(i=1; i<=n; i++)
        {
            cin>>c;
            cin>>x>>y;
            if(x!=0)
                z=x/y;

            for(k=1; k<=n; k++)
            {
                if(strcmp(c,a[k])==0)
                    f[k]-=x;
            }
            for(j=1; j<=y; j++)
            {
                cin>>b;
                for(k=1; k<=n; k++)
                {
                    if(strcmp(b,a[k])==0)
                        f[k]+=z;
                }
            }
        }
        for(i=1; i<=n; i++)
            cout<<a[i]<<' '<<f[i]<<endl;

    }

    return 0;

}
