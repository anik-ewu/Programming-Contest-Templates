#include<bits/stdc++.h>

using namespace std;

vector<int>adj[1005];
vector<int>bridge[1005];
vector<int>oneway[1005];
bool visited[1005];
int dis[1005],fin[1005],low[1005],child[1005],parent[1005],tim=0;
int nodes[1005]={0},total=0;
int color[1005]={0};
int getedge[1005][1005]={0},bridge_check[1005][1005]={0};
set<int>st;
set<int>::iterator it;
map<string,int>mp;
map<int,string>mp1;
void dfs(int s)
{
    color[s]=1;
    tim++;
    dis[s]=tim;
    low[s]=dis[s];

    for(int i=0;i<adj[s].size();i++){
        int x=adj[s][i];
        if(color[x]==1&&color[s]==1&&(getedge[x][s]==0&&getedge[s][x]==0)){
            oneway[s].push_back(x);
            getedge[x][s]=1;
            getedge[s][x]=1;
            bridge_check[s][x]=1;
        }
        if(color[x]==0){
            color[x]=1;
            parent[x]=s;
            child[s]++;
            oneway[s].push_back(x);
            bridge_check[s][x]=1;
            getedge[x][s]=1;
            getedge[s][x]=1;
            dfs(x);
            if(low[x]>dis[s]){
                if(bridge_check[s][x]==0)
                    oneway[s].push_back(x);
                else
                    oneway[x].push_back(s);

            }
            low[s]=min(low[x],low[s]);
        }
        else if(x!=parent[s]){
            if(dis[x]<low[s]) low[s]=dis[x];
        }

    }
    color[s]=2;
}
int power(int x,int y)
{
   int n=1,i;
   for(i=0;i<y;i++)
      n*=x;
   return n;
}
int toInteger(string s)
{
    int num=0,i,l,x;
    l=s.size();
    for(i=0;i<l;i++){
        x=s[i]-48;
        num+=x*power(10,l-i-1);
    }
    return num;
}

int main()
{
    int t,n,m,i,j,u,v,k,l,cnt,cas=0;
    string s,s1,s2;
    while(1)
    {
        cin>>n>>m;
        cas++;
        if(n==0&&m==0) return 0;
        memset(child,0,sizeof(child));
        memset(parent,-1,sizeof(parent));
        memset(getedge,0,sizeof(getedge));
        memset(bridge_check,0,sizeof(bridge_check));
        memset(color,0,sizeof(color));
        st.clear();
        tim=0,total=0;
        cnt=0;
        for(i=0;i<=n+2;i++){
            adj[i].clear();
            oneway[i].clear();
        }
        for(i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
            dfs(1);
        cout<<cas<<endl<<endl;
        for(i=1;i<=n;i++){
            for(j=0;j<oneway[i].size();j++){
                cout<<i<<" "<<oneway[i][j]<<endl;
            }
        }

        cout<<"#"<<endl;
    }
    return 0;
}
