#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b,c,n,ans1,ans2,i,k,j;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(a<b)
            cout<<"impossible"<<endl;
        else if(a==b)
            cout<<a<<' '<<0<<endl;
        else
        {
            c=a-b;
            ans1=(c/2)+b;
            if(c%2!=0)
                cout<<"impossible"<<endl;
            else
            {
                ans2=c/2;
                cout<<ans1<<' '<<ans2<<endl;
            }
        }
    }
    return 0;
}
