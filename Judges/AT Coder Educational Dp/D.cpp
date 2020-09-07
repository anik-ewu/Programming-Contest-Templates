#include<bits/stdc++.h>
using namespace std;
#define sz 100005
typedef long long ll;
int arr[101];
int brr[101];
ll dp[101][sz];

ll cal(int n, int val){
    if(n<=0)return 0;
    if(val<=0)return 0;
    if(dp[n][val]!=-1)return dp[n][val];

    ll a=cal(n-1,val);
    ll b=0;
    if(val-arr[n]>=0){
        b=brr[n]+cal(n-1,val-arr[n]);
    }
    return dp[n][val]=max(a,b);
}

int main(){

    int n,val;
    cin>>n>>val;
    for(int i=1;  i<=n; i++){
        cin>>arr[i]>>brr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<cal(n,val)<<endl;

    return 0;
}
