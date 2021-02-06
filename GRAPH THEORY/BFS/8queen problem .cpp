///GRAPH      :BFS [ IN 2d grid]
///Complexity :O(v+e)

///Eight Queen Problem : Given two position of a queen( h1,h2) in 8x8 chess board, we have to find the minimum step to reach from h1 to h2

#include<bits/stdc++.h>
using namespace std;
#define sz 9
int matrix[sz+1][sz+1];
int color[sz+5][sz+5],dist[sz+5][sz+5];

int dx[]={-2, -1, 1, 2, -2, -1, 1, 2};
int dy[]={-1, -2, -2, -1, 1, 2, 2, 1};

void init(){
    memset(matrix,0,sizeof(matrix));
    memset(color,0,sizeof(color));
    memset(dist,0,sizeof(dist));
}

bool valid(int x, int y){
    if(x>=1 and x<=8 and y>=1 and y<=8)return true;///inside grid
    return false;
}

int bfs(int x1,int y1,int x2,int y2)
{
    queue< pair < int, int > > q;
    q.push({x1,y1}),color[x1][y1]=1, dist[x1][y1]=0;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if(x==x2 and y==y2)return dist[x][y]; /// reached destination

        for(int i=0; i<8; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];

            if(valid(xx,yy)){

                if(color[xx][yy]==0){
                    q.push({xx,yy});/// newly visited
                    color[xx][yy]=1;
                    dist[xx][yy]=dist[x][y]+1;
                 }
                else{
                    dist[xx][yy]=min(dist[x][y]+1,dist[xx][yy]); /// previously visited
                }
            }
        }
    }
    return -1; ///not rechable
}

int main()
{

    int x1,y1,x2,y2,b,i,vertex,edge,source;

    cin>>x1>>y1>>x2>>y2;
    init();
    int step = bfs(x1,y1,x2,y2);

    if(step<0)cout<<"Not Reachable "<<endl;
    else cout<<step<<endl;

    ///print dist array to check validity


    return 0;
}
