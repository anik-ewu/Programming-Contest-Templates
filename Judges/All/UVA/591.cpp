#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[55],c,i,j,x=1,y,k;
    while(cin>>a)
    {
        j=0;
        c=0;
        k=0;
        if(a==0){break;}
        for(i=1; i<=a; i++)
        {
            cin>>b[i];
            c=c+b[i];
        }
        k=c/a;
        for(i=1; i<=a; i++)
        {
            if(b[i]>k){j=j+(b[i]-k);}
        }
        cout<<"Set #"<<x<<endl;
        cout<<"The minimum number of moves is "<<j<<"."<<endl<<endl;
        x++;

    }
    return 0;
}
