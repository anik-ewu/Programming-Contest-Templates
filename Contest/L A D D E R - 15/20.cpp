///Date : 1.5.2020
///Tags : Graph+DFS
///Idea : Find the number of components and reduced by 1

#include<bits/stdc++.h>
using namespace std;

int n;
bool visit[101];
vector < int > adj[101];

struct st{
    int x,y;
}arr[101];

void dfs(int u){
    visit[u]=1;
    for(int i=1; i<=n; i++){
        if(visit[i]==0 && (arr[i].x==arr[u].x || arr[i].y==arr[u].y)){
            dfs(i);
        }
    }
}

int main(){

    int i;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>arr[i].x;
        cin>>arr[i].y;
    }
    int component=0;
    memset(visit,0,sizeof(visit));
    for(i=1; i<=n; i++){
        if(visit[i]==0){
            dfs(i);
            component++;
        }
    }
    cout<<component-1<<endl;



    return 0;
}
