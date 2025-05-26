//https://codeforces.com/contest/2053/problem/C
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

unordered_map<ll, pair<ll, ll>> dp;

pair<ll, ll> solve(ll l, ll r, ll k){
    ll len = r - l + 1;
    if (len < k)
        return {0, 0};
    if (dp.find(len) != dp.end()){
        auto cur = dp[len];
        return {cur.first + (l - 1) * cur.second, cur.second};
    }
    ll mid = l + r >> 1;
    if (len & 1){
        auto left = solve(l, mid - 1, k);
        auto right = solve(mid + 1, r, k);
        return dp[len] = {left.first + right.first + mid, left.second + right.second + 1};
    }
    auto left = solve(l, mid, k);
    auto right = solve(mid + 1, r, k);
    return dp[len] = {left.first + right.first, left.second + right.second};
}

void solve(){
    ll n, k;
    cin >> n >> k;
    dp.clear();
    solve(1, n, k);
    cout << dp[n].first << ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
