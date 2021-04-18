#include<bits/stdc++.h>
using namespace std;
#define sz 5000010
int par[sz],ranks[sz];
void Make_Set(int n){
    for(int i=1; i<=n; i++){
        par[i]=i;
        ranks[i]=0;
    }
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(ranks[x]>ranks[y]) par[y]=x;
    else if(ranks[x]<ranks[y]) par[x]=y;
    else par[y]=x,ranks[x]+=1;
}
int main(){
    ///need to update
}
/*
Sample Input :
7 6
1 2
1 3
4 5
6 7
5 6
3 7
*/
