#include<bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001][1001];


int main(){

    int t,n,m,i,j,k,cs=1;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int sum=0;
        for(i=1; i<=n+1; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        for(i=1; i<=n; i++){
            if(cal(1,i))
        }

    }



    return 0;
}
