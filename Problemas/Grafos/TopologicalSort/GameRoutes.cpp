//https://cses.fi/problemset/task/1681/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 100001;
const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[MAXN];
int d[MAXN];
bool visited[MAXN];
stack<int> topsort;

void dfs(int u) {
    visited[u] = true;
    for (const auto &v: adj[u])
        if (!visited[v])
            dfs(v);
    topsort.push(u);
}

void bfs() {
    d[0] = 1;
    while (!topsort.empty()) {
        int u = topsort.top();
        topsort.pop();
        for (const auto &v: adj[u])
            d[v] = (d[v] % MOD + d[u] % MOD) % MOD;
    }
}


void solve() {
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    dfs(0);
    fill(d, d + n, 0);
    bfs();
    cout << d[n - 1] << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
