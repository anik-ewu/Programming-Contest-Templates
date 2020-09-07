#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,i,x,n,y=1;
    for(i=1; i<=10002; i++)
    {
        cin>>a>>b;
        if(a==0 && b==0)break;
        c=(26*b)+b;
        if(c<a)
            cout<<"Case "<<i<<": impossible"<<endl;
        else
        {
            x=b;
            y=0;
            while(x<a)
            {
                x=x+b;
                y++;
            }
            cout<<"Case "<<i<<": "<<y<<endl;

        }

    }
    return 0;
}
