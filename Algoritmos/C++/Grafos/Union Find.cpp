vector<int>pi, Size;
int Find(int u) {
    int aux = u;
    while (u != pi[u])
        u = pi[u];
    while (aux != pi[aux]) {
        aux = pi[aux];
        pi[aux] = u;
    }
    return u;
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
