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
int dp[MAXN];

int solve(int u) {
    if (dp[u] != -1)
        return dp[u];
    if (u == n - 1)
        return dp[u] = 1;
    int ans = 0;
    for (const auto &v: adj[u])
        ans = (ans % MOD + solve(v) % MOD) % MOD;
    return dp[u] = ans;
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
    fill(dp, dp + n, -1);
    cout << solve(0) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
