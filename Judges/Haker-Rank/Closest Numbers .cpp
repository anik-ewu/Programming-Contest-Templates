#include<bits/stdc++.h>
using namespace std;
int arry[200005];
int min_diff(int n)
{
    int a,b,i,ans=999999999;
    for(i=1; i<n; i++)
    {
        a=abs(arry[i]-arry[i+1]);
        ans=min(ans,a);
    }
    return ans;

}
int main()
{
    int a,b,c,i,j,k,t,n,m,q,x,y;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>arry[i];
    }
    sort(arry+1,arry+t+1);
    a=min_diff(t);
    for(i=1; i<t; i++)
    {
        b=abs(arry[i]-arry[i+1]);
        if(a==b)
        {
            cout<<arry[i]<<' '<<arry[i+1];
            if(i+1<t)
                cout<<' ';
        }
    }
    cout<<endl;

    return 0;
}


