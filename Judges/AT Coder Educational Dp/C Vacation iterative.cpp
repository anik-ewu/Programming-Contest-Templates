///At Coder  : Vacation
///Approach  : Iterative Dp
///Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

int dp[100005][4];
int arr[100005][4];

int main(){

    ios_base::sync_with_stdio(false);cout.tie(false);cin.tie(false);

    int n,i,j,a;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>arr[i][1];
        cin>>arr[i][2];
        cin>>arr[i][3];
    }
    for(i=1; i<=n; i++){
       dp[i][1]=arr[i][1]+max(dp[i-1][2],dp[i-1][3]);
       dp[i][2]=arr[i][2]+max(dp[i-1][1],dp[i-1][3]);
       dp[i][3]=arr[i][3]+max(dp[i-1][1],dp[i-1][2]);
    }
    cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;

    return 0;
}

