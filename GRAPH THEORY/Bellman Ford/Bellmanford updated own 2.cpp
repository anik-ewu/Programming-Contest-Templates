#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
const ll INF=1e9;
ll dis[N];
int par[N];
struct edge{
    int a, b, w;
};
vector< edge > G;

void bellmanford(int s, int n, int m){

    for(int i=1; i<=n; i++)
        dis[i]=INF;

    dis[s]=0;
    int x;
    for(int k=1; k<=n; k++){
        x=-1;
        for(auto i: G){
            int u=i.a; int v=i.b; int w=i.w;
            if(dis[u]<INF){
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    par[v]=u;
                    x=v;
                }
            }
        }
    }
    if(x!=-1){
        int y = x;
        for (int i=1; i<=n; ++i){
            y = par[y];
        }

        vector<int> path;
        for (int cur=y; ; cur=par[cur]){
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';

        exit(0);
    }

}

int main(){

    int n, m, a, b, w;
    cout<<"here"<<endl;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a>>b>>w;
        //G.push_back({a, b, w});
    }
    //bellmanford(1, n, m);///passing source and the vertex no to function


    return 0;
}
/*
5 6
1 2 1
2 3 1
2 4 1
3 4 -4
4 5 0
5 2 0

*/
