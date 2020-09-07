#include<bits/stdc++.h>
using namespace std;

int arr[150];
int brr[150];

void init()
{
    for(int i=1; i<=120; i++){
        arr[i]=i;
        brr[i]=i;
    }
}

long long int ncr( int n, int m)
{
    long long int i,j,ans=1,x;
    if(n==m)
        return 1;

    for(i=2; i<=n-m; i++){
        for(j=m+1; j<=n; j++){
            int id=__gcd(arr[j],brr[i]);
            arr[j]/=id;
            brr[i]/=id;
        }
    }

    for(i=m+1; i<=n; i++){
        x=arr[i];
        ans = ans *x;
    }
    return ans;
}

int main()
{
    int n, m;

    while(cin>>n>>m){
        if(n==0 and m==0)
            break;

        init();

        long long int ans=ncr(n,m);

        cout<<n<<" things taken "<<m<<" at a time is "<<ans<<" exactly."<<endl;
    }
    return 0;
}
