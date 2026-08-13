struct LCA {
    int n, LOG;
    vector<vector<int> > adj;

    // Euler Tour
    vector<int> euler;
    vector<int> depth;
    vector<int> first;

    // Sparse Table sobre posiciones del Euler Tour
    vector<vector<int> > st;
    vector<int> lg;

    LCA(int n) : n(n) {
        adj.resize(n);
        first.assign(n, -1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p, int d) {
        depth[u] = d;

        first[u] = euler.size();
        euler.push_back(u);

        for (int v: adj[u]) {
            if (v == p) continue;

            dfs(v, u, d + 1);

            euler.push_back(u);
        }
    }

    void build(int root = 1) {
        depth.resize(n);

        // Euler Tour
        dfs(root, 0, 0);

        int m = euler.size();

        // log[i] = floor(log2(i))
        lg.resize(m + 1);
        for (int i = 2; i <= m; i++)
            lg[i] = lg[i / 2] + 1;

        LOG = lg[m] + 1;

        // st[k][i] = nodo de menor profundidad
        // en [i, i + 2^k - 1]
        st.assign(LOG, vector<int>(m));

        for (int i = 0; i < m; i++)
            st[0][i] = euler[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= m; i++) {
                int a = st[k - 1][i];
                int b = st[k - 1][i + (1 << (k - 1))];

                st[k][i] = (depth[a] < depth[b] ? a : b);
            }
        }
    }

    // O(1)
    int query(int u, int v) {
        int l = first[u];
        int r = first[v];

        if (l > r)
            swap(l, r);

        int k = lg[r - l + 1];

        int a = st[k][l];
        int b = st[k][r - (1 << k) + 1];

        return depth[a] < depth[b] ? a : b;
    }

    int dist(int u, int v) {
        int w = query(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};
