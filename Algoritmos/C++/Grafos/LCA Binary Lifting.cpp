const int MAXN = 200005;
const int LOG = 20;
VI adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
int n, q;

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (parent[u][i - 1] != -1)
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }

    for (int v: adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int binaryLifting(int u, int x) {
    for (int i = 0; i < LOG; i++)
        if (x & (1 << i)) {
            if (u == -1) return -1;
            u = parent[u][i];
        }
    return u;
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    a = binaryLifting(a, depth[a] - depth[b]);
    if (a == b)return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] == parent[b][i])
            continue;
        a = parent[a][i];
        b = parent[b][i];
    }
    return parent[a][0];
}
