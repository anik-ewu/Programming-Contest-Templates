///Problem  : UVA: 11690
///Approach : Disjoint Set
///Idea     : It's possible if all the set has a sum equal to zero

#include<bits/stdc++.h>
#define sz         10005
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;
int arr[sz],par[sz],Rank[sz];
void Make_Set(int n){
    for(int i=0; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
    }
}

int find(int a){
    if(par[a]==a) return a;
    return par[a]=find(par[a]);
}

void Union(int a, int b){

    int x=find(a);
    int y=find(b);

    if(Rank[x]>Rank[y])par[y]=x;
    else if(Rank[x]<Rank[y])par[x]=y;
    else par[y]=x,Rank[x]++;
}

int main(){

    FastRead
    int a,b,c, n,m, i,j,k,t,  q,l,r, sum,ans,mn,mx,cnt,cs=1;

    cin>>t;
    while(t--){
        cin>>n>>m;
        Make_Set(n);
        for(i=0; i<n; i++)cin>>arr[i];
        for(i=1; i<=m; i++){
            cin>>a>>b;
            if(par[find(a)]!=par[find(b)]){
                Union(a,b);
            }
        }
        for(i=0; i<n; i++)
            par[i]=find(i);
        for(i=0; i<n; i++){
            int idx=par[i];
            if(idx!=i)arr[idx]+=arr[i],arr[i]=0;
        }
        bool possible=true;
        for(i=0; i<n; i++){
            if(arr[i]!=0){
                possible=false;
            }
        }
        if(possible){
            cout<<"POSSIBLE"<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }

     return 0;
}

