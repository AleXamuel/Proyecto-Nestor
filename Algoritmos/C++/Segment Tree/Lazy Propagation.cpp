//this implementation works for assignments on ranges and queries with sum on ranges you only need to change apply and push methods
struct LazyST {
    int n;
    vector<long long> st;
    vector<long long> lazy;
    vector<bool> marked;

    LazyST() {}

    LazyST(int sz) {
        init(sz);
    }

    void init(int sz) {
        n = sz;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        marked.assign(4 * n, false);
    }

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }

        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);

        st[v] = st[v << 1] + st[v << 1 | 1];
    }

    void build(vector<int> &a) {
        init(a.size());
        build(a, 1, 0, n - 1);
    }

    void apply(int v, int tl, int tr, long long val) {
        st[v] = (tr - tl + 1LL) * val;
        lazy[v] = val;
        marked[v] = true;
    }

    void push(int v, int tl, int tr) {
        if (!marked[v] || tl == tr)
            return;

        int tm = (tl + tr) >> 1;

        apply(v << 1, tl, tm, lazy[v]);
        apply(v << 1 | 1, tm + 1, tr, lazy[v]);

        marked[v] = false;
    }

    void update(int v, int tl, int tr, int l, int r, long long val) {
        if (l > r)
            return;

        if (l == tl && r == tr) {
            apply(v, tl, tr, val);
            return;
        }

        push(v, tl, tr);

        int tm = (tl + tr) >> 1;

        update(v << 1, tl, tm, l, min(r, tm), val);
        update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);

        st[v] = st[v << 1] + st[v << 1 | 1];
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;

        if (l == tl && r == tr)
            return st[v];

        push(v, tl, tr);

        int tm = (tl + tr) >> 1;

        return query(v << 1, tl, tm, l, min(r, tm))
             + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int l, int r, long long val) {
        update(1, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
