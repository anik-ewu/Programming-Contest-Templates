#include<iostream>
#include<vector>
using namespace std;

#define sz 1000000
#define mod 1000000000
#define inf 10000000000000000
int len;
int arr[50];
long long int dp[100][sz+5];

int cal(int n,int m){

     int i,j;
     for(i=0; i<=m; i++)dp[0][i]=0;
     for(i=0; i<=n; i++)dp[i][0]=1;

     for(i=1; i<=len; i++){
        for(j=1; j<=m; j++){
            if(arr[i]>j){
                dp[i][j]=(dp[i-1][j]);
            }
            else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i]]);
            }
            if(dp[i][j]>inf)dp[i][j]=dp[i][j]%mod;
        }
     }
     return dp[n][m];
}

void po(){
    int i=1;
    len=1;
    while(i<=sz){
        arr[len++]=i;
        i=i<<1;
    }
}

int main(){
    po();
    int n;
    //cout<<arr[]
    cin>>n;
    cout<<cal(len,n)<<endl;


    return 0;
}
