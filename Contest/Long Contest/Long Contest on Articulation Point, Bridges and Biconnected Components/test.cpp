#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#include<climits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = 1e8 + 5;
const ll inf = 1e15 + 5;
const db eps = 1e-9;

struct Edge {
    ll u, v, c;
} e[maxn<<2];
struct Ed {
    ll v, c;
};
int n, m, low[maxn], pre[maxn], tim, ebcc_cnt, du[maxn];
ll k, len, dis[maxn][2];
vector<int> G[maxn];
vector<Ed> ed[maxn];
int isbri[maxn<<4];
bool vis[maxn];

void init() {
    ebcc_cnt = tim = 0;
    for (int i = 1; i <= n; i++) G[i].clear();
    memset(isbri, 0, sizeof(isbri));
    memset(pre, 0, sizeof(pre));
    memset(du, 0, sizeof(du));
}

void tarjan(int u, int fa) {
    low[u] = pre[u] = ++tim;
    for (int i = 0; i < G[u].size(); i++) {
        int tmp = G[u][i];
        int v = e[tmp].v;
        if (!pre[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > pre[u]) // 子节点的反向边大于当前节点
                isbri[tmp] = isbri[tmp^1] = true; //标记为桥
        }
        else if (fa != v) // fa很重要 对于桥
            low[u] = min(low[u], pre[v]);
    }
}

void dfs(int u) {
    pre[u] = ebcc_cnt;
    for (int i = 0; i < G[u].size(); i++) {
        int tmp = G[u][i];
        if (isbri[tmp]) continue;
        int v = e[tmp].v;
        if (pre[v]) continue;
        dfs(v);
    }
}

void find_ebcc() {
    tarjan(1, -1);
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) {
        if (!pre[i]) {
            ebcc_cnt++;
            dfs(i);
        }
    }
}

void BFS(int s, int ca) {
    memset(vis, 0, sizeof(vis));
    queue<Ed> q;
    q.push((Ed){s, 0});
    vis[s] = 1;
    while (q.size()) {
        Ed tmp = q.front(); q.pop();
        dis[tmp.v][ca] = tmp.c;
        for (int i = 0; i < ed[tmp.v].size(); i++) {
            Ed xx = ed[tmp.v][i];
            if (!vis[xx.v]) {
                vis[xx.v] = 1;
                q.push((Ed){xx.v, xx.c + tmp.c});
            }
        }
    }
}

void dfs_len(int x, int fa, ll dep) {   //找直径
    if (dep > len) {
        k = x;
        len = dep;
    }
    for (int i = 0; i < ed[x].size(); i++) {
        Ed tmp = ed[x][i];
        if (tmp.v == fa) continue;
        dfs_len(tmp.v, x, dep + tmp.c);
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        e[i<<1|1].u = u, e[i<<1|1].v = v, e[i<<1|1].c = c;
        e[i<<1].u = v, e[i<<1].v = u, e[i<<1].c = c;
        G[u].push_back(i<<1|1);
        G[v].push_back(i<<1);
    }
    find_ebcc();
    int tot = m<<1|1;
    for (int i = 1; i <= ebcc_cnt; i++) ed[i].clear();
    for (int i = 1; i <= tot; i += 2) {
        if (isbri[i]) {
            int u = e[i].v, v = e[i].u;
            ed[pre[u]].push_back((Ed){pre[v], e[i].c});
            ed[pre[v]].push_back((Ed){pre[u], e[i].c});
        }
    }
    len = -1;
    dfs_len(1, -1, 0);
    int st = k; len = -1;
    dfs_len(st, -1, 0);
    BFS(st, 0); //直径的两个端点
    BFS(k, 1);
    ll inx = n + 1, dd = inf;
    for (int i = 1; i <= n; i++) {
        int pr = pre[i];
        if (dis[pr][0] + dis[pr][1] != len) continue;   //判断是否是直径上的点
        ll tmp = max(dis[pr][0], dis[pr][1]);
        if (tmp < dd) {
            inx = i;
            dd = tmp;
        }
    }
    cout << inx << ' ' << dd << endl;
}

int main() {
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("hh.txt", "w", stdout);
    int t = 1; cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
/*
2
7 7
1 2 5
1 7 5
3 2 5
1 3 5
3 4 3
6 4 1
4 5 3
3 3
1 2 3
1 3 3
2 3 3
*/
