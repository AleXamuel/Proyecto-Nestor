//https://www.spoj.com/problems/QTREE/
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
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                       query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
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
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    ST(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        buildST(a, 1, 0, n - 1);
    }

    ST(int sz) {
        n = sz;
        t.assign(4 * n, 0);
    }

    ST() {
    }

    void init(int sz) {
        n = sz;
        t.assign(4 * n, 0);
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
    res = max(last_heavy_path_max, res);
    return res;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int> > adj((n << 1) - 1, vector<int>());
    vector<int> A(n + n - 1, 0);
    For(i, 0, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb(i + n);
        adj[i + n].pb(u);
        adj[v].pb(i + n);
        adj[i + n].pb(v);
        A[i + n] = w;
    }
    init(adj);
    segment.init(n+n-1);
    For(i, 0, A.size())
        segment.update(pos[i], A[i]);
    //DBGV(pos);
    //DBGV(A);
    while (true) {
        string s;
        cin >> s;
        if (s == "DONE")
            break;
        if (s == "QUERY") {
            int l,r;cin>>l>>r;
            l--,r--;
            cout<<query(l,r)<<ln;
        } else {
            int u,x;
            cin>>u>>x;
            u--;
            segment.update(pos[n+u],x);
        }
    }
}

signed main() {
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Tim = 1;
    cin >> Tim;
    while (Tim--) {
        solve();
    }
    return 0;
}
