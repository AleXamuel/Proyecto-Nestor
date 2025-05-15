//https://cses.fi/problemset/task/1673/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 2501;
const ll INF = LLONG_MAX;
int n;
vector<pair<int,ll> > adj[MAXN];
vector<pair<int,ll> > adjT[MAXN];
ll d[MAXN];
bool visited1[MAXN];
bool visited2[MAXN];


void dfs1(int u) {
    visited1[u] = true;
    for (const auto &e: adj[u]) {
        int v = e.first;
        if (!visited1[v])
            dfs1(v);
    }
}

void dfs2(int u) {
    visited2[u] = true;
    for (const auto &e: adjT[u]) {
        int v = e.first;
        if (!visited2[v])
            dfs2(v);
    }
}


bool bellmand() {
    fill(d, d + n, INF);
    d[0] = 0;
    bool hayCambios = true;
    for (int i = 1; i < n && hayCambios; i++) {
        hayCambios = false;
        for (int u = 0; u < n; u++)
            for (const auto &e: adj[u]) {
                int v = e.first;
                ll w = e.second;
                if (d[u] != INF && d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    hayCambios = true;
                }
            }
    }

    for (int u = 0; u < n; u++)
        for (const auto &e: adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (d[u] != INF && d[u] + w < d[v])
                if (visited1[u] && visited2[u])
                    return false;
        }
    return true;
}


void solve() {
    int m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].emplace_back(b, -w);
        adjT[b].emplace_back(a, -w);
    }
    fill(visited1, visited1 + n, false);
    dfs1(0);
    fill(visited2, visited2 + n, false);
    dfs2(n - 1);
    if (bellmand())
        cout << -d[n - 1];
    else
        cout << -1;
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
