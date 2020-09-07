#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i,j,k,x,y,z,n,t;
    while(cin>>n>>t)
    {
        x=n;
        k=0;
        while(n>0)
        {
            b=0;
            for(i=1; i<=t; i++)
            {
                cin>>a;
                if(a==0 && b==0)
                {
                    k++;
                    b=1;
                }
            }
            n--;
        }
        x=x-k;
        cout<<x<<endl;

    }
    return 0;
}
