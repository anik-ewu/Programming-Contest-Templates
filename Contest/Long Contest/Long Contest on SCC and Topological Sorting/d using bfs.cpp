///Topsort in increasing order possible
///Remember: to put a dot and a blank line after each test case and
///In the case there is no relation between two beverages,
/// Dilbert should start drinking the one that appears first in the input

#include<bits/stdc++.h>
using namespace std;

#define sz 101

bool vis[sz];
int indeg[sz];
vector< int > adj[sz];
map <string, int > mp;
map <int, string > mpp;

void topsort(int n){

    priority_queue<int> q;
    vector< int > ans;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0)q.push(-i),vis[i]=1;
    }
    while(!q.empty()){
        int u=q.top()*-1;
        q.pop();
        ans.push_back(u);
        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            indeg[v]--;
            if(indeg[v]==0 and vis[v]==0){
                vis[v]=1;
                q.push(-v);
            }
        }
        cout<<' '<<mpp[u];
    }
}


int main(){
    ///Fast;///using Fast I/O
    string s,p;
    int a,b,c, i,j,k, t,n,m, cs=1;

    while(cin>>n){
        mp.clear();mpp.clear();
        for(i=1; i<=n; i++)adj[i].clear(),vis[i]=0,indeg[i]=0;
        for(i=1; i<=n; i++){
            cin>>s;
            mp[s]=i;
            mpp[i]=s;
        }
        cin>>m;
        for(i=1; i<=m; i++){
            cin>>s>>p;
            a=mp[s];b=mp[p];
            adj[a].push_back(b);
            indeg[b]++;
        }
        cout<<"Case #"<<cs++<<": Dilbert should drink beverages in this order:";
        topsort(n);
        cout<<'.'<<endl<<endl;
    }
    return 0;
}
