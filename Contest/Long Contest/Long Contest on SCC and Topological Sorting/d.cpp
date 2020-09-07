///23-8-2020
///Top sort
///Don't forget to print the black line and a dot(.);

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              105

bool vis[sz];
stack< int > st;
vector< int > adj[sz];
map <string, int > mp;
map <int, string > mpp;

void dfs(int u){
    vis[u]=1;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    st.push(u);
}

void solve(int n){

    for(int i=1; i<=n; i++){
        if(vis[i]==0)dfs(i);
    }
    while(!st.empty()){
        cout<<' '<<mpp[st.top()];
        st.pop();
    }
    cout<<'.'<<endl;
}

int main(){
    Fast;///using Fast I/O
    string s,p;
    int a,b,c, i,j,k, t,n,m, cs=1;

    ///freopen("out.txt","w",stdout);

    while(cin>>n){
        mp.clear();mpp.clear();
        for(i=1; i<=n; i++)adj[i].clear(),vis[i]=0;
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
        }
        if(cs>1)cout<<endl;
        cout<<"Case #"<<cs++<<": Dilbert should drink beverages in this order:";
        solve(n);
    }
    return 0;
}
