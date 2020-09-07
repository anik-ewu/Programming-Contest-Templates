///At Coder  : Frog 2
///Approach  : Recursive DP
///Complexity: O(n*k)

#include<bits/stdc++.h>
using namespace std;

int k;
int dp[100005];
int arr[100005];

int frog(int pos, int n){

    if(pos==n)return 0;
    if(dp[pos]!=-1)return dp[pos];

    int a=abs(arr[pos]-arr[pos+1])+frog(pos+1,n);
    int b=INT_MAX;
    for(int i=2; i<=k; i++){
        if(pos+i<=n){
           b=abs(arr[pos]-arr[pos+i])+frog(pos+i,n);
           a=min(a,b);
        }
        else
            break;
    }
    return dp[pos]=a;

}

int main(){

    ios_base::sync_with_stdio(false);cout.tie(false);cin.tie(false);

    int n,i;
    cin>>n>>k;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        dp[i]=-1;
    }
    cout<<frog(1,n)<<endl;


    return 0;
}

