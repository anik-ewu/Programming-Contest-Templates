#include<bits/stdc++.h>
using namespace std;

int n,m;
int mp[1002][1002];
double dp[1002][1002];

double cal(int x, int y){
    if(x==n && y==m)return 0;
    if(x>n || y>m)return INT_MAX;
    if(dp[x][y]!=-1.0){
        return dp[x][y];
    }
    double a,b,c,mn;
    a=100.0+cal(x+1,y);
    b=100.0+cal(x,y+1);
    mn=min(a,b);
    if(mp[x][y]==1){
        c=141.421356237+cal(x+1,y+1);
        mn=min(mn,c);
    }
    return dp[x][y]=mn;
}

int main(){


    int k,x,y;
    cin>>n>>m;
    n++;m++;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++)
            mp[i][j]=0,dp[i][j]=-1.0;
    }
    cin>>k;
    for(int i=1; i<=k; i++){
        cin>>x>>y;
        mp[x][y]=1;
    }
    double ans=cal(1,1);
    int ff=round(ans);
    cout<<ff<<endl;
    return 0;
}
