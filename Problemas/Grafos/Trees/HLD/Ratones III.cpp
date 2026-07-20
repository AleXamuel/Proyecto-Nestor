//https://codeforces.com/gym/106063/problem/L
#include <bits/stdc++.h>
using namespace std;
#define dll long double
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define sz(A) (int)A.size()
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define VVI vector<vector<ll>>
const int MAX = 2e5 + 1, MOD = 1e9 + 7, INF = 1e9, base = 27;
#define int ll

struct LazyST {
    int n;
    vector<long long> st;
    vector<long long> lazy;
    vector<bool> marked;

    LazyST() {
    }

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
        st[v]%=MOD;
    }

    void build(vector<int> &a) {
        init(a.size());
        lazy.assign(4 * n, 1);
        marked.assign(4 * n, false);
        build(a, 1, 0, n - 1);
    }

    void apply(int v, int tl, int tr, long long val) {
        st[v] *=  val;
        st[v]%=MOD;
        lazy[v] *= val;
        lazy[v]%=MOD;
        marked[v] = true;
    }

    void push(int v, int tl, int tr) {
        if (!marked[v] || tl == tr)
            return;

        int tm = (tl + tr) >> 1;

        apply(v << 1, tl, tm, lazy[v]);
        apply(v << 1 | 1, tm + 1, tr, lazy[v]);
        lazy[v]=1;
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
        st[v]%=MOD;
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;

        if (l == tl && r == tr)
            return st[v];

        push(v, tl, tr);

        int tm = (tl + tr) >> 1;

        return (query(v << 1, tl, tm, l, min(r, tm))
               + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r))%MOD;
    }

    void update(int l, int r, long long val) {
        update(1, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int> > const &adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c: adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int> > const &adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c: adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int> > const &adj) {
    int n = adj.size();
    parent = vector<int>(n, -1);
    depth = vector<int>(n, 0);
    heavy = vector<int>(n, -1);
    head = vector<int>(n, 0);
    pos = vector<int>(n, 0);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

LazyST segment;

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment.query(pos[head[b]], pos[b]);
        res += cur_heavy_path_max;
        res%=MOD;
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment.query(pos[a], pos[b]);
    res += last_heavy_path_max;
    res%=MOD;
    return res;
}

void update(int l, int r, int x) {
    for (; head[l] != head[r]; r = parent[head[r]]) {
        if (depth[head[l]] > depth[head[r]])
            swap(l, r);
        segment.update(pos[head[r]], pos[r], x);
    }
    if (depth[l] > depth[r])
        swap(l, r);
    segment.update(pos[l], pos[r], x);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > adj(n+n-1, vector<int>());
    vector<int>A(n+n-1,0),B(n+n-1);
    For(i, 0, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb(i+n);
        adj[i+n].pb(u);
        adj[v].pb(i+n);
        adj[i+n].pb(v);
        A[i+n]=w;
    }
    init(adj);
    //DBGV(A);
    //DBGV(pos);
    For(i,0,n+n-1)
        B[pos[i]]=A[i];

    segment.build(B);

    while (q--) {
        int u,v,x;cin>>u>>v>>x;
        u--,v--;
        cout<<(query(u,v)*x)%MOD<<ln;
        update(u,v,x);
    }
}

signed main() {
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Tim = 1;
    //cin >> Tim;
    while (Tim--) {
        solve();
    }
    return 0;
}
