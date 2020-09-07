///Date     : 1.5.2020
///Tags     : Graph+DFS
///Idea     : Find the number of components and reduced by 1 + no of employee who know 0 languages
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[101];
int mat[101][101];
vector < int > vv[101];

int dfs(int u){
    vis[u]=1;
    for(int i=0; i<vv[u].size(); i++){
        int v=vv[u][i];
        for(int j=1; j<=n; j++){
            if(vis[j]==0 && mat[j][v]==1){
                dfs(j);
            }
        }
    }
}

int main(){

    int nn,a,j,i,m;
    int com=0,cnt=0;
    memset(vis,0,sizeof(vis));

    cin>>n>>m;
    for(i=1; i<=n; i++){
        cin>>nn;
        if(nn==0)cnt++,vis[i]=1;
        for(j=1; j<=nn; j++){
            cin>>a;
            mat[i][a]=1;
            vv[i].push_back(a);

        }
    }

    for(i=1; i<=n; i++){
        if(vis[i]==0){
            com++;
            dfs(i);
        }
    }
    if(com)com-=1;
    cout<<com+cnt<<endl;


    return 0;
}
