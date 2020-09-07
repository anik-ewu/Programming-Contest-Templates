#include<iostream>
#include<queue>
using namespace std;
int matrix[100][100],colour[100];
int p[100],d[100],f[100],time=0,x=0,forest=0;
void dfs_visit(int u, int n){
    forest++;
    time++;
    d[u]=time;
    colour[u]=1;
    for(int i=1; i<=n; i++){
        if(matrix[u][i]==1 && colour[i]==0){
            colour[i]=1;
            p[i]=u;
            dfs_visit(i,n);
        }
    }
    time++;
    f[u]=time;
    colour[u]=2;
}

void  DFS(int v){

    int i;
    for(i=1; i<=v; i++){
        colour[i]=p[i]=0,d[i]=200,f[i]=200;
    }
    time=0;
    for(i=1; i<=v; i++){
        forest=0;
        if(colour[i]==0)
            dfs_visit(i,v);
        x=max(x,forest);
    }
}

int main()
{

    int a,b,i,j,vertex,edge,s;
    cin>>vertex>>edge;
    for(i=1; i<=edge; i++)
    {
        cin>>a>>b;
        matrix[a][b]=1;
        /// matrix[b][a]=1;
    }
    DFS(vertex);
    cout<<x<<endl;

    return 0;
}

