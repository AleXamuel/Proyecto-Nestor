vector<int>pi, sz;
int Find(int u) {
    if (pi[u] == u)return u;
    return pi[u] = Find(pi[u]);
}

void Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y)
        return;
    if (sz[x] < sz[y]) {
        pi[x] = y;
        sz[y] += sz[x];
    } else {
        pi[y] = x;
        sz[x] += sz[y];
    }
}
