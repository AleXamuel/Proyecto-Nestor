//https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
int const MOD = 1e9 + 7;

void solve() {
    int n, val;
    cin >> n >> val;
    vector<int> coins(n);
    vector<vector<int> > dp(n + 1, vector<int>(val + 1, 0));

    for (int &x: coins)
        cin >> x;

    dp[0][0] = 1;
    For(i, 1, n + 1) {
        For(j, 0, val + 1) {
            dp[i][j] = dp[i - 1][j] % MOD;
            int left = j - coins[i - 1];
            if (left >= 0)
                (dp[i][j] += dp[i][left] % MOD) % MOD;
        }
    }

    cout << dp[n][val] % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
