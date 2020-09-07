#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10],b[10],i,j,k,x,y,z;
    while(cin>>a[1])
    {
        k=0;
        for(i=2; i<=5; i++)
            cin>>a[i];
        for(i=1; i<=5; i++)
        {
            cin>>b[i];
            if(a[i]==b[i])
                k=1;
        }
        if(k==0)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;

    }
    return 0;
}
