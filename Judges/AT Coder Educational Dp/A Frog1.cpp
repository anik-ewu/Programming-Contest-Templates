///At Coder  : Frog 1
///Approach  : Iterative Dp
///Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

int dp[100005];
int arr[100005];

#define inf INT_MAX
int frog(int pos, int n){
    int a,b;
   for(int i=2; i<=n; i++){
       a=abs(arr[i-1]-arr[i])+dp[i-1];
       b=abs(arr[i-2]-arr[i])+dp[i-2];
       if(i==2){
        dp[i]=a;
       }
       else{
        dp[i]=min(a,b);
       }
   }
   return dp[n];
}

int main(){

    ios_base::sync_with_stdio(false);cout.tie(false);cin.tie(false);

    int n,i;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<frog(1,n)<<endl;


    return 0;
}
