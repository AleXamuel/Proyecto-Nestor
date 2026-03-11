//https://atcoder.jp/contests/abc448/tasks/abc448_e
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl


const int P = 10007;


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

ll inv(ll a,ll mod) {
    return binpow(a, mod - 2, mod);
}

void solve() {
    int k;
    ll M;
    cin >> k >> M;
    ll nmodP = 0;
    ll nmodM = 0;
    For(i, 0, k) {
        int c;
        ll l;
        cin >> c >> l;
        nmodP *= binpow(10, l, P);
        nmodP %= P;
        nmodP += c * ((binpow(10, l, P) - 1) * inv(9, P));
        nmodP %= P;

        nmodM *= binpow(10, l, M);
        nmodM %= M;
        nmodM += c * ((binpow(10, l, 9 * M) - 1) / 9);
        nmodM %= M;
    }
    nmodM %= P;
    ll ans = (nmodP - nmodM) % P;
    if (ans < 0)
        ans += P;
    cout << (ans * inv(M, P)) % P << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}
