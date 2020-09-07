#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,b,c,d,e,f;

    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>a>>b>>c;
        if(a<21 && b<21 && c<21)

            cout<<"Case "<<i<<": good"<<endl;
        else

            cout<<"Case "<<i<<": bad"<<endl;
    }

    return 0;
}
