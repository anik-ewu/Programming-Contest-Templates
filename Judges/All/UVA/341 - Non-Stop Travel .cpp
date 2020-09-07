//#Floyed Warshal
#include<bits/stdc++.h>
using namespace std;

#define X 110
vector < int >v;
long long int adj[X][X],par[X][X];

int floyed_warshall(int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(adj[i][j]>adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                    par[i][j]=par[k][j];
                }
            }
        }
    }
    return 0;
}
void init(int n){

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            adj[i][j]=INT_MAX,par[i][j]=i;
        }
    }


}

void printPath(int i, int j) {
    if (i != j) printPath(i, par[i][j]);
        printf(" %d", j);
}


int main(){

    int cs=1,n,a,b,i,j,k,weight,src,des;

    while(cin>>n){
        if(!n)break;
        init(n);
        for(i=1; i<=n; i++){
            cin>>k;
            for(j=1; j<=k; j++){
            cin>>b>>weight;
            adj[i][b]=weight;
        }
      }
      cin>>src>>des;
      floyed_warshall(n);
      cout<<"Case "<<cs++<<": Path =";
      printPath(src,des);
      cout<<"; "<<adj[src][des]<<" second delay"<<endl;
      v.clear();
    }

    return 0;
}





