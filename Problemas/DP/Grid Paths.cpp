//https://cses.fi/problemset/task/1638/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long
#define size(l,r) (r-l+1)
const int MOD = 1e9 + 7;

vector<string> grid;
vector<vector<int> > dp;
int n;

int solve(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (grid[i][j] == '*')
        return dp[i][j] = 0;
    if (i == n - 1 && j == n - 1)
        return dp[i][j] = 1;
    return dp[i][j] = (solve(i, j + 1) % MOD + solve(i + 1, j) % MOD) % MOD;
}

void solve() {
    cin >> n;
    grid.assign(n, " ");
    For(i, 0, n)
        cin >> grid[i];
    dp.assign(n, vector<int>(n, -1));
    cout << solve(0, 0) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
