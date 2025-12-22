//https://codeforces.com/contest/1985/problem/E
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


vector<ll> f(ll n) {
    vector<ll> ans;
    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i)
                ans.push_back(n / i);
        }
    return ans;
}

void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> divs = f(k);
    ll ans = 0;
    for (const auto &i: divs)
        for (const auto &j: divs)
            if (k % (i * j) == 0) {
                ll w = k / (i * j);
                if (i - 1 <= x && j - 1 <= y && w - 1 <= z)
                    ans = max(ans, (x - (i - 1)) * (y - (j - 1)) * (z - (w - 1)));
            }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
