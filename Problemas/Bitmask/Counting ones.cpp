//https://vjudge.net/problem/UVA-12670
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


ll f(ll n) {
    n++;
    ll ans = 0;
    For(i, 0, 64) {
        ll val = n / (1ll << i);
        ans += (val / 2ll) * (1ll << i);
        if (n % (1ll << i) > 0 && (val & 1ll)) {
            ans += n % (1ll << i);
        }
    }
    return ans;
}

void solve() {
    ll a, b;
    while (cin >> a >> b)
        cout << f(b) - f(a - 1) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
