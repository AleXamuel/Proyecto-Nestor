//https://atcoder.jp/contests/dp/tasks/dp_p
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

const int MOD = 1e9 + 7;

int n;
vector<vector<int> > adj;
vector<pair<int, int> > dp;


int dfs(int u, int par, int col) {
    if (adj[u].size() == 1 && u != 0)
        return 1;
    if (col == 0 && dp[u].first != -1)
        return dp[u].first;
    if (col == 1 && dp[u].second != -1)
        return dp[u].second;
    long long c = 1;
    for (const auto &v: adj[u]) {
        if (v == par)continue;
        int val = dfs(v, u, 0);
        if (col != 1) {
            val += dfs(v, u, 1);
            val %= MOD;
        }
        c *= val;
        c %= MOD;
    }
    if (col == 0)
        return dp[u].first = c;
    return dp[u].second = c;
}

void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    fori(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.assign(n, {-1, -1});
    dfs(0, -1, 0);
    dfs(0, -1, 1);
    cout << (dp[0].first + dp[0].second) % MOD << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
