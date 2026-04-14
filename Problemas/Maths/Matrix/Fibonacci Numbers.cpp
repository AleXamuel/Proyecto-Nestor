//https://cses.fi/problemset/task/1722/
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
#define LOG2(x) (31 - __builtin_clz(x))
#define LOG2LL(x) (63 - __builtin_clzll(x))
#define nextpow2(x) 1 << (32 - __builtin_clz(x))
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
const int MAXN = 1e5 + 1;

struct Matrix {
    //ajustar tamaño
    ll m[2][2];

    Matrix() {
        memset(m, 0, sizeof(m));
    }

    Matrix operator*(const Matrix &o) const {
        Matrix res;
        //ajuste el tamaño, ajustado para 2 
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) % MOD;
        return res;
    }
};

Matrix powmat(Matrix base, ll exp) {
    Matrix res;
    res.m[0][0] = res.m[1][1] = 1; // identidad, si es tamaño tres agregue m[2][2]

    while (exp > 0) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << ln;
        return;
    }

    Matrix base;
    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;

    Matrix power = powmat(base, n - 1);
    cout << power.m[0][0] << ln;
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
