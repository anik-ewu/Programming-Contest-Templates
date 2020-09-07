#include<bits/stdc++.h>
using namespace std;
long long int arry[1005];
bool check_sized(int n,int m, long long int  mid)
{
    long long int i,sum=0;
    for(i=1; i<=n; i++)
    {
        if(sum+arry[i]<=mid)
        {
            sum+=arry[i];
        }
        else
        {
            sum=0;
            m--;i--;
        }
        if(m==0)
            break;
    }
    if(i<n)
        return false;
    return true;
}

int binary_src(int n, int m, long long int low, long long int high)
{

    long long int ans=high, mid;
    while(low<=high)
    {

        mid =low+(high-low)/2;
        if(check_sized(n,m,mid))
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main()
{
    long long int b,c,i,j,k,x,y,n,m,t,sum;

    cin>>t;
    for(j=1; j<=t; j++)
    {
        sum=0;
        cin>>n>>m;
        for(i=1; i<=n; i++)
        {
            cin>>arry[i];
            sum+=arry[i];
        }
        cout<<"Case "<<j<<": "<<binary_src(n,m,0,sum)<<endl;
    }

    return 0;
}
