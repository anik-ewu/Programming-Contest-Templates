///Problem  : UVA 10227
///Approach : Disjoint Set + Adj Matrix
///Idea     : Find the same opinion and merge them to a connected component. Then the number of components
///           (i.e: parents) will provide the total different opinion.

#include<bits/stdc++.h>
using namespace std;
string s;
int seen[101][101];
int par[101],Rank[101];
void Make_Set(int n){
    for(int i=0; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
        for(int j=0; j<=100; j++)
            seen[i][j]=0;
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

bool same_opinion(int i, int j, int Total_Tree){

    for(int k=1; k<=Total_Tree; k++){
        if(seen[i][k]!=seen[j][k])return false;
    }
    return true;
}

int main(){

    int t,n,m,i,j,a,b,k,cs=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        Make_Set(n);
        getchar();
        while(getline(cin,s)){
            if(s.size()==0)break;
            stringstream line(s);
            line>>a;///string to int
            line>>b;///string to int
            seen[a][b]=1;
        }

        for(i=1; i<=n; i++){
            for(j=1;j<=n; j++){
                if(same_opinion(i,j,m)){
                    if(par[find(i)]!=par[find(j)])
                        Union(i,j);
                }
            }
        }

        set< int > opinion;
        for(i=1; i<=n; i++)
            opinion.insert(find(i));

        if(cs)cout<<endl;
        cs=1;
        cout<<opinion.size()<<endl;

    }
    return 0;
}
