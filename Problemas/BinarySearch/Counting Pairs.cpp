//https://codeforces.com/contest/2051/problem/D
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (ll i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

const int MAX = 2e5;

ll A[MAX];
ll n;

ll bs1(ll l,ll x) {
    ll r = n - 1;
    ll ans = -1;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (A[mid] <= x) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ans;
}

ll bs2(ll l,ll x) {
    ll r = n - 1;
    ll ans = -1;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (A[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

void solve() {
    ll x, y;
    cin >> n >> x >> y;
    ll cum = 0;
    For(i, 0, n) {
        cin >> A[i];
        cum += A[i];
    }
    sort(A, A + n);
    ll ans = 0;
    For(i, 0, n) {
        ll a = bs1(i + 1, cum - x - A[i]);
        ll b = bs2(i + 1, cum - y - A[i]);
        if (a == -1 || b == -1)
            continue;
        ans += a - b + 1;
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
    return 0;
}
