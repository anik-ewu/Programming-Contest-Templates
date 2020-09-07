#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b[1000],i,j,k,x,y=1,n;
    char a[10000][100];
    cin>>n;
    while(n>0)
    {
        x=0;
        for(i=1; i<=10; i++)
        {
            cin>>a[i]>>b[i];
            if(b[i]>x)
                x=b[i];
        }
        cout<<"Case #"<<y<<":"<<endl;
        for(i=1; i<=10; i++)
        {
            if(b[i]==x)
            cout<<a[i]<<endl;
        }
        y++;
        n--;
    }
    return 0;

}
