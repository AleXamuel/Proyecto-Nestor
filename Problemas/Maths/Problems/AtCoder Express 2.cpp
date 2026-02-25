//https://atcoder.jp/contests/abc106/tasks/abc106_d
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define PI acos(-1)
#define RAD(deg) ((deg) * PI / 180.0)
#define ln "\n"

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pcc = pair<char, char>;

//const ll INF = 1e18;
const double eps = 1e-9;
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const int INF = 1e9;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll> > A(n + 1, vector<ll>(n + 1, 0));
    For(i, 0, m) {
        int l, r;
        cin >> l >> r;
        A[l][r]++;
    }

    vector<vector<ll> > pref(n + 1, vector<ll>(n + 1, 0));
    For(i, 1, n + 1)
        For(j, 1, n + 1)
            pref[i][j] = A[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = pref[n][r] - pref[l - 1][r];
        cout << ans << ln;
    }
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
