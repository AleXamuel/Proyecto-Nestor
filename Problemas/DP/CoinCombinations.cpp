//https://cses.fi/problemset/task/1635

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
    ll n, val;
    cin >> n >> val;
    vector<ll> coins(n);
    vector<ll> dp(val + 1, 0);
    for (ll &x: coins) {
        cin >> x;
        if (x <= val)
            dp[x] = 1;
    }
    sort(all(coins));
 
    For(i, 1, val + 1) {
        For(j, 0, n) {
            if (coins[j] <= i)
                dp[i] += dp[i - coins[j]] % MOD;
        }
    }
 
    cout << dp[val] % MOD << ln;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
