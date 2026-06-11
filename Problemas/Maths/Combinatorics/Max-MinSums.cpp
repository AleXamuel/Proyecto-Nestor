//https://atcoder.jp/contests/abc151/tasks/abc151_e
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define ones(x) __builtin_popcount(x)
#define VI vector<int>
#define VVI vector<VI>
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(), (v).end()
#define ln "\n"

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pcc = pair<char, char>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);
const int MAXN = 2000005;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    For(i, 0, n)
        cin >> A[i];

    sort(all(A));

    vector<ll> fact(n + 1), invfact(n + 1);

    fact[0] = 1;
    For(i, 1, n + 1)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[n] = modpow(fact[n], MOD - 2);
    Rfor(i, n, 1)
        invfact[i - 1] = invfact[i] * i % MOD;


    auto C = [&](int n, int k) -> ll {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    };

    ll ans = 0;

    For(i, 0, n) {
        ll asMax = C(i, k - 1);
        ll asMin = C(n - i - 1, k - 1);

        ll add = (asMax - asMin) % MOD;
        if (add < 0)
            add += MOD;
        ans = (ans + A[i] % MOD * add) % MOD;
    }

    cout << ans % MOD << ln;
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
