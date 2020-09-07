#include<bits/stdc++.h>
using namespace std;
#define sz 11
int n,m;
int arr[sz];
int dp[sz][sz];
int f(int prev, int len){
    if(len==n) return 1;
    if(dp[prev][len]!=-1)return dp[prev][len];
    int a=0;
    for(int k=1; k<=m; k++){
        if(abs(arr[k]-prev)<=2){
            a+=f(arr[k],len+1);
        }
    }
    return dp[prev][len]=a;
}

int main(){

    int cs=1,t,i;
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(i=1; i<=m; i++)cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(i=1; i<=m; i++){
            sum+=f(arr[i],1);
        }
        cout<<"Case "<<cs++<<": "<<sum<<endl;
    }
    return 0;
}
