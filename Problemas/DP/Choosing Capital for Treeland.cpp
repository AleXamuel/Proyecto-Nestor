//https://codeforces.com/contest/219/problem/D
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 2e5 + 1;
int n;
vector<pair<int, bool> > adj[MAXN];
int dp[MAXN];
bool visited[MAXN];

void dfs1(int u) {
    visited[u] = true;
    for (const auto &e: adj[u]) {
        int v = e.first;
        bool dir = e.second;
        if (!visited[v]) {
            if (!dir)
                dp[0]++;
            dfs1(v);
        }
    }
}

void dfs2(int u) {
    visited[u] = true;
    for (const auto &e: adj[u]) {
        int v = e.first;
        int dir = e.second;
        if (!visited[v]) {
            if (dir)
                dp[v] = dp[u] + 1;
            else
                dp[v] = dp[u] - 1;
            dfs2(v);
        }
    }
}


void solve() {
    cin >> n;
    For(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].emplace_back(b, true);
        adj[b].emplace_back(a, false);
    }
    fill(dp, dp + n, 0);
    fill(visited, visited + n, false);
    dfs1(0);
    fill(visited, visited + n, false);
    dfs2(0);
    int ans = *min_element(dp, dp + n);
    cout << ans << ln;
    For(i, 0, n)
        if (dp[i] == ans)
            cout << i + 1 << " ";
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
