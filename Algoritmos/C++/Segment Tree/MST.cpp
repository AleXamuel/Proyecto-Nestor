vector<int> t[4*MAXN];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}
int query(int v, int tl, int tr, int l, int r, int k) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v].end() - upper_bound(t[v].begin(), t[v].end(), k);
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm), k) +
           query(v*2+1, tm+1, tr, max(l, tm+1), r, k);
}
