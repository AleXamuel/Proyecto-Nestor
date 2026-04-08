//https://cses.fi/problemset/task/1686/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

struct SCC {
    int n, cnt;
    vector<vector<int> > g, rg;
    vector<int> order, comp_id;
    vector<vector<int> > comps, dag;
    vector<bool> vis;

    SCC(int n) : n(n) {
        g.assign(n, {});
        rg.assign(n, {});
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v: g[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    }

    void dfs2(int u, int c) {
        comp_id[u] = c;
        comps[c].push_back(u);
        for (int v: rg[u]) {
            if (comp_id[v] == -1) dfs2(v, c);
        }
    }

    void build() {
        vis.assign(n, false);
        order.clear();

        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i);
        }

        reverse(order.begin(), order.end());

        comp_id.assign(n, -1);
        comps.clear();
        cnt = 0;

        for (int u: order) {
            if (comp_id[u] == -1) {
                comps.push_back({});
                dfs2(u, cnt);
                cnt++;
            }
        }

        //DAG BUILD
        dag.assign(cnt, {});
        for (int u = 0; u < n; u++) {
            for (int v: g[u]) {
                int a = comp_id[u];
                int b = comp_id[v];
                if (a != b) dag[a].push_back(b);
            }
        }

        for (int i = 0; i < cnt; i++) {
            sort(dag[i].begin(), dag[i].end());
            dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    VI A(n);
    For(i, 0, n)
        cin >> A[i];

    SCC scc(n);
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        scc.add_edge(a, b);
    }
    scc.build();

    vector<ll> compCoins(scc.cnt, 0);
    For(u, 0, n)
        compCoins[scc.comp_id[u]] += A[u];

    vector<ll> dp(scc.cnt, -1);
    function<ll(int)> dfs = [&](int u) -> ll {
        if (dp[u] != -1)
            return dp[u];

        dp[u] = compCoins[u];
        for (int v: scc.dag[u]) {
            dp[u] = max(dp[u], dfs(v) + compCoins[u]);
        }
        return dp[u];
    };

    ll ans = 0;
    For(i, 0, scc.cnt)
        ans = max(ans, dfs(i));

    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
