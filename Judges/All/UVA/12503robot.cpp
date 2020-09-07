#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,x,y,z,t,p;
    char a[1000][10],b[1000][10];
    cin>>n;
    while(n>0)
    {
        cin>>t;
        getchar();
        p=0;
        for(i=1; i<=t; i++)
        {
            //gets(a[i]);
            cin>>a[i];
            if(a[i][0]=='L')
                p--;
            else if(a[i][0]=='R')
                p++;
            else if(a[i][0]=='S')
            {
                getchar();
                cin>>b[i];
                cin>>x;
                strcpy(a[i],a[x]);
            if(a[i][0]=='L')
                p--;
            else if(a[i][0]=='R')
                p++;
            }
        }
        cout<<p<<endl;
        n--;
    }
    return 0;
}
