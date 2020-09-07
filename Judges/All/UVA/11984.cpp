#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,d,n,i,e;
    double c,f;
    while(cin>>n)
    {
        for(i=1; i<=n; i++)
        {
            cin>>c>>f;
            if(f!=0){f=(f*5.0)/9.0;}
            c=c+f;
            cout<<"Case "<<i<<": ";
            printf("%0.2lf\n",c);
        }
    }
    return 0;
}
