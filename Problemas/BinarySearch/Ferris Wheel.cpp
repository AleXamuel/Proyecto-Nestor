//https://cses.fi/problemset/task/1090/
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (ll i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"


void solve() {
    ll n, x;
    cin >> n >> x;
    multiset<ll> Q;
    For(i, 0, n) {
        ll cur;
        cin >> cur;
        Q.insert(cur);
    }
    int ans = 0;
    while (!Q.empty()) {
        ll u = *Q.begin();
        Q.erase(Q.find(u));
        auto it = Q.upper_bound(x - u);
        if (it != Q.begin()) {
            --it;
            ll v = *it;
            Q.erase(Q.find(v));
        }
        ans++;
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
