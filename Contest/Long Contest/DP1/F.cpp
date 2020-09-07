#include<bits/stdc++.h>
using namespace std;

int arr[22][4];
int dp[22][4];

int cal(int pos, int col, int n){
    if(pos>n)return 0;

    if(dp[pos][col]!=-1)return dp[pos][col];
    int a,b;
    a=b=0;
    if(col==1){
        a+=(arr[pos][col]+cal(pos+1,2,n));
        b+=(arr[pos][col]+cal(pos+1,3,n));
    }
    else if(col==2){
        a+=(arr[pos][col]+cal(pos+1,1,n));
        b+=(arr[pos][col]+cal(pos+1,3,n));
    }
    else if(col==3){
        a+=(arr[pos][col]+cal(pos+1,2,n));
        b+=(arr[pos][col]+cal(pos+1,1,n));
    }
    return dp[pos][col]=min(a,b);
}

int main(){

    int i,t,n,m,cs=1;

    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(i=1; i<=n; i++){
            cin>>arr[i][1];
            cin>>arr[i][2];
            cin>>arr[i][3];
        }
        int a=cal(1,1,n);
        int b=cal(1,2,n);
        int c=cal(1,3,n);
        cout<<"Case "<<cs++<<": "<<min(a,min(b,c))<<endl;
    }


    return 0;
}
