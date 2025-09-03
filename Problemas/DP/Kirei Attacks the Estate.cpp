//https://codeforces.com/contest/2114/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<int,int>

const int MAX = 2e5;

vector<int> adj[MAX];

ll val[MAX];
ll dp[MAX];
int pi[MAX];
int n;


void dfs(int u, int par, int level) {
    if (level - 2 >= 0)
        dp[u] = max({val[u], val[u] - val[par] + dp[pi[par]]});
    else
        dp[u] = val[u];
    pi[u] = par;
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        dfs(v, u, level + 1);
    }
}


void solve() {
    cin >> n;
    For(i, 0, n) {
        cin >> val[i];
        adj[i].clear();
        dp[i] = pi[i] = -1;
    }
    For(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    For(i, 0, n)
        cout << dp[i] << " ";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
