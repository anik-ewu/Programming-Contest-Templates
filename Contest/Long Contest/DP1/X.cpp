#include<bits/stdc++.h>
using namespace std;
#define sz 22
int tot;
int dp[sz][sz][200];
vector < int > v[sz];

int cal(int pos, int x, int sum, int n){
    if(sum<0)return -2000000;
    if(pos>n || x>=v[pos].size())return 0;
    if(dp[pos][x][sum]!=-1)return dp[pos][x][sum];
    int a,b=0;
    a=v[pos][x]+cal(pos+1,0,sum-v[pos][x],n);
    b=cal(pos,x+1,sum,n);
    return dp[pos][x][sum]=max(a,b);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t,n,m,k,c,i,j,a,sum,mn;
    cin>>t;
    while(t--){
        cin>>m>>c;
        for(i=1; i<=c; i++)v[i].clear();
        sum=0;
        for(i=1; i<=c; i++){
            cin>>k;
            mn=INT_MAX;
            for(j=1; j<=k; j++){
                cin>>a;
                mn=min(mn,a);
                v[i].push_back(a);///clear v
            }
            sum+=mn;
        }
        memset(dp,-1,sizeof(dp));
        if(sum>m)cout<<"no solution"<<endl;
        else cout<<cal(1,0,m,c)<<endl;
    }


    return 0;
}
