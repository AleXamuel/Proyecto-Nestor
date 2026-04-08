struct SCC {
    int n, cnt;
    vector<vector<int>> g, rg;
    vector<int> order, comp_id;
    vector<vector<int>> comps, dag;
    vector<bool> vis;

    SCC(int n) : n(n) {
        g.assign(n, {});
        rg.assign(n, {});
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    }

    void dfs2(int u, int c) {
        comp_id[u] = c;
        comps[c].push_back(u);
        for (int v : rg[u]) {
            if (comp_id[v] == -1) dfs2(v, c);
        }
    }

    void build() {
        vis.assign(n, false);
        order.clear();

        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i);
        }

        reverse(order.begin(), order.end());

        comp_id.assign(n, -1);
        comps.clear();
        cnt = 0;

        for (int u : order) {
            if (comp_id[u] == -1) {
                comps.push_back({});
                dfs2(u, cnt);
                cnt++;
            }
        }

        dag.assign(cnt, {});
        for (int u = 0; u < n; u++) {
            for (int v : g[u]) {
                int a = comp_id[u];
                int b = comp_id[v];
                if (a != b) dag[a].push_back(b);
            }
        }

        for (int i = 0; i < cnt; i++) {
            sort(dag[i].begin(), dag[i].end());
            dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
        }
    }
};
