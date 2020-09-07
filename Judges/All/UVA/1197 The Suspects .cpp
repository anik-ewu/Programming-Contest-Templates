///Problem  : UVA 10685
///Approach : Disjoint Set
///Idea     : Make a chain of suspects with the student 0
#include<bits/stdc++.h>
#define sz         30005
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
int par[sz],Rank[sz];
void Make_Set(int n){
    for(int i=0; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
    }
}

int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==0 || y==0){
        par[x]=0;
        par[y]=0;
    }
    else if(Rank[x]>Rank[y])par[y]=x;
    else if(Rank[x]<Rank[y])par[x]=y;
    else par[y]=x,Rank[x]++;
}

int main(){

    FastRead
    int t,i,j,k, n,m,a,b,c,l,r,sum,ans;

    while(cin>>n>>m){
        if(n==0 && m==0)break;
        Make_Set(n);
        for(i=1; i<=m; i++){
            cin>>k;
            if(k)cin>>a;
            for(j=1; j<k; j++){
                cin>>b;
                if(par[find(a)]!=par[find(b)]){
                    Union(a,b);
                }
            }
        }
        int total_suspect=0;
        for(i=0; i<n; i++)
            par[i]=find(i);

        for(i=0; i<n; i++){
            if(par[i]==0)total_suspect++;
        }
        cout<<total_suspect<<endl;
    }
     return 0;
}
/*
Input :
7 4
4 4 1 0 6
2 6 4
3 2 5 3
2 5 6
0 0
Output:
7
*/

