///N.B: Declaring of the size of the dp array is tricky and we can
///reduce it by mod value. since k<=100,so dp[n][k] will be enough

#include<bits/stdc++.h>
using namespace std;
#define sz 10002
#define ad 7000000000
int arr[sz];
int dp[sz][102];

int mod(long long int n, int k){
    n+=ad;///
    n=n%k;
    return n;
}

int cal(int pos, int sum, int n, int k){

    if(pos>n) {
            return sum%k;
    }
    if(dp[pos][sum]!=-1)return dp[pos][sum];
    int x=mod(sum+arr[pos],k);
    int y=mod(sum-arr[pos],k);
    int a=cal(pos+1,x,n,k);
    int b=cal(pos+1,y,n,k);
    return dp[pos][sum]=min(a,b);
}

int main(){

    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1; i<=n; i++)cin>>arr[i];
        memset(dp,-1,sizeof(dp));

        int remainder=cal(1,0,n,k);
        if(remainder==0)cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }
    return 0;
}
