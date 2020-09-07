///Problem  : UVA 10685
///Approach : Disjoint Set
///Idea     : Just merge the length of the chain at the time of Union ( a, b)
#include<bits/stdc++.h>
#define sz         5005
#define FastRead   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std ;

string s,p;
vector < int >vec;
vector < string >v,va;
int par[sz],Rank[sz],chain[sz];
unordered_map < string, int >mp;

void Make_Set(int n){
    for(int i=0; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
        chain[i]=1;
    }
}

int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(Rank[x]>Rank[y])par[y]=x;
    else if(Rank[x]<Rank[y])par[x]=y;
    else par[y]=x,Rank[x]++;
    if(Rank[x]>Rank[y])chain[x]+=chain[y];
    else chain[y]+=chain[x];
}

int main(){

    FastRead
    int t,i,j,k, n,m,a,b,c,l,r,sum,ans;

    while(cin>>n>>m){
        if(n==0 && m==0)break;
        Make_Set(n);
        mp.clear();
        for(i=0; i<n; i++){
            cin>>s;
            mp[s]=i+1;
        }
        for(i=1; i<=m; i++){
            cin>>s>>p;
            a=mp[s];
            b=mp[p];
            if(par[find(a)]!=par[find(b)]){
                Union(a,b);
            }
        }
        ans=-1;
        for(i=1; i<=n; i++){
            ans=max(ans,chain[i]);
        }
        cout<<ans<<endl;
    }

     return 0;
}

