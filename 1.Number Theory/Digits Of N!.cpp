#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,d;
    double x=0;
    cin>>n;
    for(i=1; i<=n; i++)
        x+=log10(i);
    d=x;
    d+=1;
    cout<<d<<endl;
}
