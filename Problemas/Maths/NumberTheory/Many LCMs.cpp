//https://atcoder.jp/contests/abc445/tasks/abc445_e
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<ll,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


const int MAX = 1e7 + 1;
const int MOD = 998244353;

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD - 2);
}

vector<int> primos;

void criba() {
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    For(i, 2, MAX) {
        if (is_prime[i]) {
            primos.push_back(i);
            if ((ll) i * i > MAX)
                continue;
            for (int j = i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    map<int, map<int, int> > fact;
    map<int, vector<int> > P;
    for (int &i: A) {
        cin >> i;
        int aux = i;
        for (const auto &p: primos) {
            if ((ll) p * p > aux)
                break;
            int e = 0;
            while (aux % p == 0) {
                aux /= p;
                e++;
            }
            if (e > 0) {
                fact[i][p] = e;
                P[p].push_back(e);
            }
        }
        if (aux > 1) {
            fact[i][aux] = 1;
            P[aux].push_back(1);
        }
    }

    map<int, int> L;
    map<int, int> LL;
    for (const auto &e: P) {
        int p = e.first;
        vector<int> ee = e.second;
        sort(all(ee));
        L[p] = ee.back();
        ee.pop_back();
        if (sz(ee) > 0)
            LL[p] = ee.back();
    }
    ll l = 1;
    for (const auto &[p,e]: L)
        l = (l * binpow(p, e)) % MOD;

    for (const auto &i: A) {
        ll num = 1;
        ll den = 1;
        for (const auto &[p,e]: fact[i])
            if (e == L[p]) {
                den = (den * binpow(p, e)) % MOD;
                num = (num * binpow(p, LL[p])) % MOD;
            }

        ll cur_l = l;
        cur_l = (cur_l * inv(den)) % MOD;
        cur_l = (cur_l * num) % MOD;
        cout << cur_l << " ";
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    criba();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
