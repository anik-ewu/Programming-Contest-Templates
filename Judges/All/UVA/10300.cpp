#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    long long int n,m,i,j,mr,t1;
    double x,y,a,b,c,g,f,e,t2;
    while(cin>>n)
    {
        g=0;
        for(i=1; i<=n; i++)
        {

            mr=0;
            cin>>m;
            for(j=1; j<=m; j++)
            {
                cin>>a>>b>>c;
                x=a/b;
                e=x*c;
                f=e*b;
                t1=f;
                t2=f-t1;
                if(t2>0.5)
                {
                    f=f+1;
                }
                mr=mr+f;
            }
            cout<<mr<<endl;
        }
    }
    return 0;
}
