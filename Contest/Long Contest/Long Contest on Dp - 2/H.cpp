#include<bits/stdc++.h>
using namespace std;
#define sz      100005
#define ll      long long
#define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;
ll arr[sz];
ll dp[sz][4];

ll cal(int p, int cnt){
    if(cnt==3)return 1;
    if(p>n)return 0;
    if(dp[p][cnt]!=-1)return dp[p][cnt];

    int a;
    a=cal(p+1,1);
    if(p+1<=n){
        if(arr[p+1]>arr[p])
            a+=(p+1,cnt+1);
    }
    cout<<p<<' '<<a<<endl;
    return dp[p][cnt]=a;

}

int main(){

    cin>>n;
    for(int i=1; i<=n; i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    reverse(arr+1,arr+n+1);
    cout<<cal(1,1)<<endl;

    return 0;
}

