#include<bits/stdc++.h>
using namespace std;
#define sz 51

char arr[51];
char brr[51];
bool vis[sz];
char sol[sz][sz];
int matrix[sz][sz];

void build(int n){
    memset(matrix,0,sizeof(matrix));
    for(int i=1; i<=n; i++)matrix[i][i]=1;

    for(int i=1; i<=n; i++){
        if(brr[i]=='Y'){
            for(int j=1; j<=n; j++){
                if(abs(i-j)==1 && arr[j]=='Y'){
                    matrix[i][j]=1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sol[i][j]='N';
        }
    }
}

void dfs(int s, int u, int n){
    vis[u]=1;
    sol[s][u]='Y';
    for(int i=1; i<=n; i++){
        if(matrix[u][i]==1 && vis[i]==0){
            dfs(s, i, n);
        }
    }
}

void print(int cs, int n){

    cout<<"Case #"<<cs<<":"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<sol[i][j];
        }
        cout<<endl;
    }
}

int main(){

    freopen("travel_restrictions_input.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++)cin>>arr[i];
        for(int i=1; i<=n; i++)cin>>brr[i];
        build(n);
        for(int i=1; i<=n; i++)memset(vis,0,sizeof(vis)),dfs(i, i, n);
        print(cs++,n);
    }
    return 0;
}
