//https://codeforces.com/problemset/problem/118/E
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(), A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

vector<vector<pair<int, int> > > adj;
vector<pair<int, int> > edges;
vector<int> d, low;
int TIME;
bool cond;


void tarjan(int u, int par) {
    d[u] = low[u] = TIME++;
    for (const auto &ee: adj[u]) {
        int v = ee.first;
        int edge = ee.second;
        if (v == par)
            continue;
        if (d[v] == 0) {
            edges[edge] = {u + 1, v + 1};
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (d[u] < low[v]) {
                cond = false;
                return;
            }
        } else {
            edges[edge] = {v + 1, u + 1};
            low[u] = min(low[u], d[v]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<pair<int, int> >());
    fori(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    edges.assign(m, {});
    d.assign(n, 0);
    low.assign(n, 0);
    TIME = 1;
    cond = true;
    tarjan(0, -1);
    if (cond)
        for (const auto &ee: edges)
            cout << ee.first << " " << ee.second << ln;
    else
        cout << 0 << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
