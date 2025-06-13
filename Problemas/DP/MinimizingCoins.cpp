https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
 
void solve() {
    ll n, val;
    cin >> n >> val;
    vector<ll> coins(n);
    for (ll &x: coins)
        cin >> x;
    sort(all(coins));
    vector<ll> dp(val + 1, INT_MAX);
    dp[0] = 0;
    For(i, 1, val + 1) {
        For(j, 0, n) {
            if (coins[j] <= i && dp[i - coins[j] != INT_MAX])
                dp[i] = min(dp[i],dp[i - coins[j]] + 1);
        }
    }
    cout << ln;
    if (dp[val] == INT_MAX)
        cout << -1;
    else
        cout << dp[val];
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
