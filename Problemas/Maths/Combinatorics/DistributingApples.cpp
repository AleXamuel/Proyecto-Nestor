//https://cses.fi/problemset/task/1716/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll comb(ll n, ll k) {
    if (k < 0 || k > n)
        return 0;
    if (k > n - k)
        k = n - k;

    ll num = 1, den = 1;
    for (ll i = 0; i < k; i++) {
        num = num * (n - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    return num * binpow(den, MOD - 2, MOD) % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    cout << comb(n + k - 1, k) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
