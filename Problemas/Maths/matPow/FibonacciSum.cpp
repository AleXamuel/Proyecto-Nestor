//https://vjudge.net/problem/SPOJ-FIBOSUM
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define PQ priority_queue<int, vector<int>, greater<int>>
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

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);
const int MAXN = 200000 + 5;

vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> C(2, vector<ll>(2, 0));
    For(i, 0, 2)
        For(j, 0, 2)
            For(k, 0, 2)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

vector<vector<ll>> matPow(vector<vector<ll>> mat, ll n) {
    vector<vector<ll>> result = {{1, 0}, {0, 1}};

    while(n > 0) {
        if(n & 1)
            result = multiply(result, mat);
        mat = multiply(mat, mat);
        n >>= 1;
    }
    return result;
}

ll fib(ll n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<vector<ll>> base = {{1, 1}, {1, 0}};
    vector<vector<ll>> ans = matPow(base, n);

    return ans[0][1];
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll sumM = fib(m + 2);
    ll sumN = fib(n + 1);

    ll ans = (sumM - sumN + MOD) % MOD;
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
