vector<int>pi, Size;
int Find(int u) {
    if (pi[u] == u)return u;
    return pi[u] = Find(pi[u]);
}

void Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y)
        return;
    if (Size[x] < Size[y]) {
        pi[x] = y;
        Size[y] += Size[x];
    } else {
        pi[y] = x;
        Size[x] += Size[y];
    }
}
