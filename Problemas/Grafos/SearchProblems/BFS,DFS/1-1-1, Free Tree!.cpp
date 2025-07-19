//https://codeforces.com/contest/2126/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

using Edge = pair<int, int>;

constexpr int MAX = 2e5;
int n;
vector<Edge> adj[MAX];
int color[MAX];
Edge pi[MAX];
unordered_map<int, ll> A[MAX];


ll dfs(int u, int par, int cost) {
    ll ans = 0;
    pi[u] = {par, cost};
    for (const auto &[v,w]: adj[u]) {
        if (v == par)
            continue;
        if (color[v] != color[u])
            ans += w;
        A[u][color[v]] += w;
        ans += dfs(v, u, w);
    }
    return ans;
}

void solve() {
    int q;
    cin >> n >> q;
    For(i, 0, n) {
        cin >> color[i];
        adj[i].clear();
        A[i].clear();
        pi[i] = {-1, -1};
    }
    For(i, 0, n-1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    ll ans = dfs(0, -1, -1);
    while (q--) {
        int u, c;
        cin >> u >> c;
        u--;
        if (c == color[u]) {
            cout << ans << ln;
            continue;
        }
        if (pi[u].first != -1) {
            if (color[pi[u].first] == c)
                ans -= pi[u].second;
            else if (color[pi[u].first] == color[u])
                ans += pi[u].second;
            A[pi[u].first][color[u]] -= pi[u].second;
            A[pi[u].first][c] += pi[u].second;
        }
        ans += A[u][color[u]];
        ans -= A[u][c];
        color[u] = c;
        cout << ans << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
