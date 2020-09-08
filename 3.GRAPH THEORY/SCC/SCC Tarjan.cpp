///count the component of a graph
///Complexity: O(V+E)

void dfs(int u, int par){
    vis[u]=1;
    st.push(u);
    d[u]=low[u]=t++;
    for(int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if(v==u)continue;
        if(vis[v]==0){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==1){
            low[u]=min(low[u],d[v]);
        }
    }
    if(low[u]==d[u]){
        g++;
        while(1){
            int k=st.top();
            st.pop();
            low[k]=low[u];
            vis[k]=2;
            if(k==u) break;
        }
    }
}

int count_scc(int n){

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(i,0);
        }
    }
    return g;
}
