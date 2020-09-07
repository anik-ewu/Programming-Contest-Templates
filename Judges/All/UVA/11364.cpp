#include<iostream>
using namespace std;
int main()
{
    int a,b,c,n,i,j,k,x,y;
    cin>>b;
    while(b>0)
    {
        cin>>n;

        for(i=1; i<=n; i++)
        {
            cin>>a;

            if(i==1)
            {
                x=a;
                y=a;
            }
            else if(a<x)
                x=a;
            else if(a>y)
                y=a;

        }
        y=y-x;
        if(y!=0)
        {
            y=y*2;
            cout<<y<<endl;
        }
        else
            cout<<"0"<<endl;
        b--;
    }
    return 0;
}
