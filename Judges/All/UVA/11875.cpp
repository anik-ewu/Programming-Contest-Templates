#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[11],b,c,d,t,i,n,k=1;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        d=n%2;
        c=n/2;
        c=c+d;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        cout<<"Case "<<k<<": "<<a[c]<<endl;
        t--;
        k++;
    }
    return 0;
}
