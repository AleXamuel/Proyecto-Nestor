int n; 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> d, low;
vector<int> ap;
int time;
void dfs(int v, int p = -1) {
    visited[v] = true;
    d[v] = low[v] = time++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], d[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= d[v] && p!=-1)
                ap.push_back(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        ap.push_back(v);
}
void find_cutpoints() {
    time = 0;
    visited.assign(n, false);
    d.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
