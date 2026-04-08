//https://cses.fi/problemset/task/2182
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

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pcc = pair<char, char>;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int MAXN = 1e6 + 5;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (__int128)res * a % m;
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m) {
    return binpow(a, m - 2, m);
}

void solve() {
    int n;
    cin >> n;

    ll divs = 1;
    ll sum = 1;
    ll prod = 1;
    ll cnt = 1;

    For(i, 0, n) {
        ll p, k;
        cin >> p >> k;

        divs = divs * (k + 1) % MOD;

        ll num = (binpow(p, k + 1, MOD) - 1 + MOD) % MOD;
        ll den = (p - 1 + MOD) % MOD;
        sum = sum * num % MOD * modinv(den, MOD) % MOD;

        ll s = k * (k + 1) / 2 % (MOD - 1);
        ll part1 = binpow(prod, k + 1, MOD);
        ll part2 = binpow(binpow(p, s, MOD), cnt, MOD);
        prod = part1 * part2 % MOD;

        cnt = cnt * ((k + 1) % (MOD - 1)) % (MOD - 1);
    }
  
    
    cout << divs << " " << sum << " " << prod << ln;
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

/* Para hallar prod con formula de Tao:
  ll prod = 1;

    bool sq = true;
    for (auto [p, k] : f)
        if (k % 2) sq = false;

    if (sq) {
        ll root = 1;
        for (auto [p, k] : f) {
            root = root * binpow(p, k / 2, MOD) % MOD;
        }

        ll exp = 1;
        for (auto [p, k] : f) {
            exp = exp * ((k + 1) % (MOD - 1)) % (MOD - 1);
        }

        prod = binpow(root, exp, MOD);
    } else {
        ll base = 1;
        for (auto [p, k] : f) {
            base = base * binpow(p, k, MOD) % MOD;
        }

        ll exp = 1;
        bool used = false;
        for (auto [p, k] : f) {
            ll cur = k + 1;
            if (!used && cur % 2 == 0) {
                cur /= 2;
                used = true;
            }
            exp = exp * (cur % (MOD - 1)) % (MOD - 1);
        }

        prod = binpow(base, exp, MOD);
    }

*/
