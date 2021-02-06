///Graph : Bellman Ford [ Detect Negative Weight Cycle ]

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define infinity 1<<30  //2^30

int dis[sz];
bool cycle;
vector <int>adj[sz],weight[sz];

bool check_cycle(int n){
    for(int j=0; j<adj[n].size(); j++){
        int v=adj[n][j];
        if(dis[n]+weight[n][j]<dis[v]){
            return true;
        }
    }
}

bool  bellmanford(int src,int n){

     dis[src]=0;
     for(int i=1; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int v=adj[i][j];
            if(dis[i]+weight[i][j]<dis[v]){
                dis[v]=dis[i]+weight[i][j];
            }
        }
     }
     cycle =  check_cycle(n);///if it relax on nth time there will be a cycle
}

void init(int vertex){

   for(int i=0; i<=vertex; i++)
     dis[i]=infinity,adj[i].clear(),weight[i].clear();
}

int main()
{

    int t,i,j,a,b,c,src,vertex,edge;;

    scanf("%d",&t);

    for(i=1; i<=t; i++){
        scanf("%d%d",&vertex,&edge);
        init(vertex);///reset
        for(j=1; j<=edge; j++){
            scanf("%d%d%d",&a,&b,&c);
            adj[b].push_back(a);
            adj[a].push_back(b);
            weight[a].push_back(c);
            weight[b].push_back(c);
        }
        scanf("%d",&src);
        cycle=false;
        bellmanford(src,vertex);///source value

        printf("Case %d:\n",i);
        if(!cycle){
        for(int k=1; k<=vertex; k++){
            cout<<dis[k]<<' ';
          }
        }
        else{
            cout<<"Hi cycle "<<endl;
        }
    }

    return 0;
}

/*
input  :
2
3 3
1 2 -2
2 3 -1
3 1 -1
1
4 4
1 2 2
1 3 5
2 3 1
3 4 3
1
output :
Case 1:
Hi cycle
Case 2:
0 2 3 6
*/


