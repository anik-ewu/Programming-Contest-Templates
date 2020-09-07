#include<bits/stdc++.h>
using namespace std;
#define sz      2005
#define ll      long long
#define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;
ll mod;
int mark[sz][sz];
string s[sz];
ll dp[sz][sz];
int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
bool check(int x, int y){
    return ((x>=0 && x<n) && (y>=0 && y<n));
}

ll possible1(int i, int j){
    if(i>=n || j>=n)return 0;
    if(i==n-1 && j==n-1)return 1;
    if(s[i][j]=='#')return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(possible1(i+1,j),possible1(i,j+1));
}
ll fun(int i, int j){
    if(i>=n || j>=n)return 0;
    if(i==n-1 && j==n-1 && s[i][j]=='.')return 1;
    if(s[i][j]=='#')return 0;
    if(dp[i][j]!=-1) return dp[i][j]%mod;
    return dp[i][j]=((fun(i+1,j)%mod)+(fun(i,j+1)%mod))%mod;
}

bool possible(){

    memset(mark,0,sizeof(mark));
    mark[0][0]=1;
    queue< pair < int , int > > q;
    q.push({0,0});
    ///cout<<mark[n-1][n-1]<<endl;

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        ///cout<<i<<' '<<j<<endl;
        q.pop();
        for(int k=0; k<4; k++){
            int xx=i+X[k];
            int yy=j+Y[k];
            if(check(xx,yy) && mark[xx][yy]==0 && s[xx][yy]=='.'){
                mark[xx][yy]=1;
                q.push({xx,yy});
            }
        }
    }
    if(mark[n-1][n-1]==0)return false;
        return true;
}

int main(){

    cin>>n;
    for(int i=0; i<n; i++)cin>>s[i];


    mod=powl(2,31)-1;
    memset(dp,-1,sizeof(dp));
    if(possible1(0,0)){
        memset(dp,-1,sizeof(dp));
        cout<<fun(0,0)<<endl;
    }
    else if(possible()){
        cout<<"THE GAME IS A LIE"<<endl;
    }
    else{
        cout<<"INCONCEIVABLE"<<endl;
    }

    return 0;
}
