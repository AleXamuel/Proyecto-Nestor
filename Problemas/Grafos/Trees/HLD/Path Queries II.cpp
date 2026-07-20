//https://cses.fi/problemset/task/2134/
//the first version of this problem can also be solved using HLD
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
 
class ST {
public:
    vector<int> t;
    int n;
 
    int combine(int a, int b) {
        return max(a, b);
    }
 
    void buildST(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v<<1], t[v<<1|1]);
        }
    }
 
    int query(int v, int tl, int tr, int l, int r) {
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (r<=tm)
            return query(v<<1,tl,tm,l,r);
        if (l>=tm+1)
            return query(v<<1|1,tm+1,tr,l,r);
        return combine(query(v<<1, tl, tm, l, tm),
                       query(v<<1|1, tm + 1, tr, tm+1, r));
    }
 
    void updateST(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateST(v * 2, tl, tm, pos, new_val);
            else
                updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }
 
    ST(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        buildST(a, 1, 0, n - 1);
    }
 
    ST() {
    }
 
    ST(int sz) {
        n = sz;
        t.assign(3 * n, 0);
    }
 
    void build(vector<int> &A) {
        n = A.size();
        t.resize(4 * n);
        buildST(A, 1, 0, n - 1);
    }
 
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
 
    void update(int pos, int x) {
        updateST(1, 0, n - 1, pos, x);
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
 
ST segment;
 
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment.query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment.query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > adj(n, vector<int>());
    vector<int> A(n), B(n);
    For(i, 0, n)
        cin >> A[i];
    For(i, 1, n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init(adj);
    For(i, 0, n)
        B[pos[i]] = A[i];
    segment.build(B);
    while (q--) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k & 1) {
            l--;
            segment.update(pos[l], r);
        } else {
            l--, r--;
            cout << query(l, r) << " ";
        }
    }
}
 
signed main() {
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
