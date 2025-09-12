#define Pair pair<int,int>
#define eb emplace_back
int n,t;
vector<int> d;
vector<int> low;
vector<vector<int>> adj;
vector<Pair>bridge;
void dfs(int u, int par) {
    d[u] = t++;
    low[u] = d[u];
    for(int v:adj[u]) {
        if (v==par) continue;
        if (d[v]>0)
            low[u] = min(low[u], d[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v]>d[u]) bridge.eb(make_pair(u,v));
        }
    }
}
void get_bridges() {
    d.assign(n, 0);
    low.assign(n,0);
    t = 1;
    bridge.clear();
    dfs(0, -1);
}
