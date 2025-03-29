//https://codeforces.com/contest/2091/problem/F
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const ll inf = 1e18;
const int MOD = 998244353;
vector<vector<vector<ll> > > dp;
vector<string> a;
int n, m, d;
vector<vector<vector<ll> > > pref;
ll sum(int i, int j1, int j2, int f) {
    ll val = pref[i][j2][f];
    if (j1 > 0)
        val -= pref[i][j1 - 1][f];
    return val % MOD;
}

ll get(int i, int j, int f) {
    if (a[i][j] == '#')return 0;
    ll res = 0;
    if (i == n - 1)
        res++;
    if (!f) {
        res += sum(i, max(j - d, 0), min(m - 1, j + d), 1);
        res -= dp[i][j][1];
    }
    if (i < n - 1) {
        res += sum(i + 1, max(0, j - d + 1), min(m - 1, j + d - 1), 0);
    }
    return res % MOD;
}

void solve() {
    cin >> n >> m >> d;
    a.resize(n);
    For(i, 0, n)
        cin >> a[i];
    dp.assign(n, vector<vector<ll> >(m, vector<ll>(2, 0)));
    pref.assign(n, vector<vector<ll> >(m, vector<ll>(2, 0)));
    Rfor(i, n-1, 0)
        Rfor(f, 1, 0) {
            For(j, 0, m)
                pref[i][j][f] = dp[i][j][f] = get(i, j, f);
            For(j, 1, m)
                pref[i][j][f] += pref[i][j - 1][f];
        }
    ll ans = 0;
    For(i, 0, m)
        ans += dp[0][i][0];
    cout << ans%MOD << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti;
    cin >> ti;
    while (ti--) {
        solve();
    }
    return 0;
}

//freopen("socdist.in", "r",stdin);
//fr    eopen("socdist.out", "w", stdout)
