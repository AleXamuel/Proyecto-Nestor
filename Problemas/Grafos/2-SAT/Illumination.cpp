//https://open.kattis.com/problems/illumination
#include <bits/stdc++.h>
using namespace std;

#define precision(x) setprecision(x) << fixed
#define For(i, k, n) for (int i = k; i < n; ++i)
#define Rfor(i, n, k) for (int i = n; i >= k; --i)
#define all(v) v.begin(), v.end()

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;

struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int> > adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices),
                                used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }

    void dfs1(int v) {
        used[v] = true;
        for (int u: adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u: adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

void solve() {
    int n, r, k;
    cin >> n >> r >> k;
    TwoSatSolver solver(k);
    vector<pii> pos(k);
    For(i, 0, k) {
        cin >> pos[i].first >> pos[i].second;
        pos[i].first--, pos[i].second--;
    }

    For(i, 0, k) {
        For(j, i + 1, k) {
            int ri = pos[i].first, ci = pos[i].second;
            int rj = pos[j].first, cj = pos[j].second;
            //no pueden ambos estar en la misma fila
            if (ri == rj && abs(ci - cj) <= 2 * r)
                solver.add_disjunction(i, true, j, true);
            //no pueden ambos estar en la misma columna
            if (ci == cj && abs(ri - rj) <= 2 * r)
                solver.add_disjunction(i, false, j, false);
        }
    }

    cout << (solver.solve_2SAT() == true) << ln;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
