#include<bits/stdc++.h>
using namespace std;
#define sz      200005
#define ll      long long
#define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
int n,m;
string s[501];
bool mark[501][501];
int cost[501][501];

bool check(int x, int y){
    return ((x>=0 && x<n) && (y>=0 && y<m));
}

int bfs(){

    mark[0][0]=1;
    cost[0][0]=0;
    queue< pair < int , int > > q;
    q.push({0,0});

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int xx=i+((s[i][j]-'0')*X[k]);
            int yy=j+((s[i][j]-'0')*Y[k]);

            if(check(xx,yy) && mark[xx][yy]==0){
                mark[xx][yy]=1;
                cost[xx][yy]=cost[i][j]+1;
                q.push({xx,yy});
            }
        }
    }

    if(mark[n-1][m-1]==0)return -1;
        return cost[n-1][m-1];
}

int main(){

    fast
    int a,b, i,j,k;
    cin>>n>>m;
    for(i=0; i<n; i++)cin>>s[i];

    cout<<bfs()<<endl;

    return 0;
}

