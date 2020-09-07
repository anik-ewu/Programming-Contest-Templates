///At Coder  : Frog 1
///Approach  : Recursive DP
///Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

int dp[100005];
int arr[100005];

int frog(int pos, int n){

    if(pos==n)return 0;
    if(dp[pos]!=-1)return dp[pos];

    int a=0,b=INT_MAX;
    if(pos+1<=n)
        a=abs(arr[pos]-arr[pos+1])+frog(pos+1,n);
    if(pos+2<=n)
        b=abs(arr[pos]-arr[pos+2])+frog(pos+2,n);

    return dp[pos]=min(a,b);
}

int main(){

    ios_base::sync_with_stdio(false);cout.tie(false);cin.tie(false);

    int n,i;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        dp[i]=-1;
    }
    cout<<frog(1,n)<<endl;


    return 0;
}

