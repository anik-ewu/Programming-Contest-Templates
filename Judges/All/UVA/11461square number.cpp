#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i,j,k,z,n=201;
    double x,y;
    while(cin>>a>>b)
    {

        y=0;
        if(a==0 && b==0)
            break;
        for(i=a; i<=b; i++)
        {
            x=sqrt(i);
            z=x;
            if(x==z)
                y++;
        }
        cout<<y<<endl;
    }
    return 0;
}
