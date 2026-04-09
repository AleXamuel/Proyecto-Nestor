//https://cses.fi/problemset/task/1715/

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
const int MAXN = 1e6 + 5;
vector<ll> fact;
vector<ll> invFact;

ll modPow(ll base, ll exp, ll mod) {
    ll res = 1, x = base % mod;
    while (exp > 0) {
        if (exp & 1) res = res * x % mod;
        x = x * x % mod;
        exp >>= 1;
    }
    return res;
}

void getFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = modPow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 1; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll ncr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int freq[26] = {};
    for (char c: s)
        freq[c - 'a']++;

    ll ans = fact[n];
    For(i, 0, 26)
        ans = ans * invFact[freq[i]] % MOD;
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    getFactorials(MAXN);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
