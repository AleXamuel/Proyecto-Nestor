struct EulerCircuit {
    int n = -1, m = -1, ok = 1;
    vector<vector<Pair > > adj;
    vector<Pair > edges;
    vector<int> degree, ans, vis, taken;
    EulerCircuit(vector<Pair > &_edges) {
        edges = _edges;
        m = edges.size() - 1;
        for (auto [u,v]: edges)
            n = max({n, u, v});
        adj.resize(n + 1);
        vis.assign(n + 1, 0);
        taken.assign(m + 1, 0);
        degree.assign(n + 1, 0);
        For(i, 1, m+1) {
            auto [u,v] = edges[i];
            adj[u].pb({v, i});
            adj[v].pb({u, i});
            degree[u]++;
            degree[v]++;
        }
        For(i, 1, n+1)
            if (degree[i]&1)
                ok=0;
    }
    void dfs(int u) {
        while (!adj[u].empty()) {
            auto [v,id]=adj[u].back();
            adj[u].pop_back();
            if(taken[id])
                continue;
            taken[id] = 1;
            dfs(v);
        }
        ans.pb(u);
    }
    vector<int> solve() {
        if(!ok)
            return {-1};
        taken.assign(m+1,0);
        dfs(1);
        For(i,1,m+1)
            if(!taken[i])
                return {-1};
        return ans;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Pair> e={{0,0}};
    For(i, 0, m) {
        int u, v;
        cin >> u >> v;
        e.pb({u, v});
    }
    EulerCircuit eul(e);
    auto ans=eul.solve();
    if(ans[0]==-1||ans.size()!=m+1)
        cout<<"IMPOSSIBLE"<<ln;
    else
        for(int i:ans)
            cout<<i<<" ";
}
