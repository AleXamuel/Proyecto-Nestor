//https://codeforces.com/contest/2132/problem/C1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

ll bs(ll x) {
    ll l = 0;
    ll r = 30;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (pow(3, mid) <= x) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}

ll cost(ll x) {
    ll val = pow(3, x);
    return val * 3 + x * (val / 3);
}


void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll cur = bs(n);
    while (cur != -1) {
        ans += cost(cur);
        n -= pow(3, cur);
        cur = bs(n);
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
