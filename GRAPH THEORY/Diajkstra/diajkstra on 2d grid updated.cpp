///Diajkstra on 2d Grid
///Uva 929 - Number Maze

#include<bits/stdc++.h>
using namespace std;

#define sz 1000
#define infinity INT_MAX
typedef pair<int,pair<int,int> >PIP;
///priority_queue<PIP, vector<PIP >, greater<PIP > > pq;
priority_queue< PIP > pq;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int w[sz][sz],cost[sz][sz];

void diajkstra(int a, int b, int n, int m){

    cost[a][b]=w[a][b];
    pq.push({w[a][b],{a,b}});

    while(!pq.empty()){
        int d=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;

        pq.pop();
        ///if the current cost is is less than d , skip it
        if(cost[x][y]<d*-1)continue;
        for(int k=0; k<4; k++){
           int xx=x+dx[k];
           int yy=y+dy[k];
           if(xx>=1 and yy>=1 and xx<=n and yy<=m and cost[xx][yy]>cost[x][y]+w[xx][yy]){
                cost[xx][yy]=cost[x][y]+w[xx][yy];
                pq.push({cost[xx][yy]*-1,{xx,yy}});
           }
        }
    }
}

int main(){

    int t, n, m, i, j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                scanf("%d",&w[i][j]);
                cost[i][j]=infinity;
            }
        }
        diajkstra(1,1,n,m);
        printf("%d\n",cost[n][m]);
    }


    return 0;
}

/*
input :
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5
output :
24
15

*/
