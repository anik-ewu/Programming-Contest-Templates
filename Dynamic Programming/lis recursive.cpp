#include<bits/stdc++.h>
using namespace std;
#define sz 1005
int n;
int arr[sz];
int dp[sz][sz];

int lis(int p, int prev){
       if(p>n)return 0;
       if(prev>=0 && dp[p][prev]!=-1)return dp[p][prev];
       int a,b=0;
       a=lis(p+1,prev);
       if(arr[p]>prev){
        b=1+lis(p+1,arr[p]);
       }
       return dp[p][prev]=max(a,b);
}

void path(int p, int len){
    if(p>n)return ;
    if(lis(p,arr[p])==len-1){
        cout<<arr[p]<<endl;
        path(p+1,len-1);
    }
    else{
        path(p+1,len);
    }
}

int main(){

    cin>>n;
    for(int i=1; i<=n; i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<lis(1,-1)<<endl;///length of the lis
    path(1,lis(1,-1));///values of the list

    return 0;
}
///Input  : 16 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
///Output : 6
