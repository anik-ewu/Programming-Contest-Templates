#include<bits/stdc++.h>
using namespace std;
#define sz 20001
int n;
int arr[101];
int dp[202][sz];
int dp2[102][sz];

int cal(int pos, int sum, int m){
    if(sum>=m)return sum;
    if(pos>n)return INT_MAX;
    if(dp[pos][sum]!=-1)return dp[pos][sum];
    int b=cal(pos+1,sum+arr[pos],m);
    int c=cal(pos+1,sum,m);
    return dp[pos][sum]=min(b,c);
}

int cal2(int bill){

    memset(dp2,0,sizeof(dp2));
    int i, j;
    for(i=0; i<=bill; i++)dp2[0][i]=0;
    for(i=0; i<=n; i++)dp2[i][0]=1;

    for(i=1; i<=n; i++){
        for(j=1; j<=bill; j++){
            if(arr[i]>j){
                dp2[i][j]=dp2[i-1][j];
            }
            else{
                int a=0, b=0;
                a=dp2[i-1][j];
                if(dp2[i-1][j-arr[i]])
                    b=dp2[i-1][j-arr[i]]+1;
                if(a && b)
                    dp2[i][j]=min(a,b);
                else if(a || b)
                    dp2[i][j]=max(a,b);
            }
        }
    }
      int mn=INT_MAX;
      for(int i=1; i<=n; i++){
        if(dp2[i][bill])
            mn=min(mn,dp2[i][bill]);
      }

    return mn;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,m,i;
    cin>>t;
    while(t--){
        cin>>m;
        cin>>n;
        for(i=1; i<=n; i++){
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans=cal(1,0,m);
        int cnt=cal2(ans);
        cout<<ans<<' '<<cnt<<endl;
    }


    return 0;
}
