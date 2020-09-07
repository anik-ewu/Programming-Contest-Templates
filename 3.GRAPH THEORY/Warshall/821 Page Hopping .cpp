#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool flag=false;
ll adj[200][200], arr[200];

void init(){
    for(int i=0; i<=101; i++)
        for(int j=0; j<=101; j++)
            adj[i][j]=INT_MAX,arr[i]=0;
}

void floyed_warshall(){
    int i,j,k;
    for(k=1;k<101;k++){
        for(i=1;i<101;i++){
            for(j=1;j<101;j++){
                if(arr[i] and arr[j] and arr[k])
                 adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}

void cal(int cas){

    double sum=0,cnt=0.0;
    for(int i=1; i<=100; i++){
        if(arr[i])cnt++;
        for(int j=1; j<=100; j++){
            if(adj[i][j]<INT_MAX and i!=j){
                sum+=adj[i][j];
            }
        }
    }
    cnt=(cnt*(cnt-1.0));
    sum/=cnt;
    printf("Case %d: average length between pages = %0.3lf clicks\n",cas,sum);
}


int main(){

    int a,b,cs=1;
    init();
    while(cin>>a>>b){
        if(a==b and b==0 and flag){
            break;
        }
        else if(a==b and b==0){
            flag = true;
            floyed_warshall();
            cal(cs);
            init();
            cs++;
        }
        else{
            flag=false;
            adj[a][b]=1;
            arr[a]=1;
            arr[b]=1;
        }
    }
    return 0;
}

