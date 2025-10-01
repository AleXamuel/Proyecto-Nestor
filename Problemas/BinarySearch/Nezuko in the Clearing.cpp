//https://codeforces.com/contest/2149/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<ll,ll>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, A.size()-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

ll g(ll n) {
    return (n * (n + 1)) >> 1;
}

bool valid(ll m, ll h, ll d) {
    ll y = m + 1;
    ll c = (d + y - 1) / y;
    ll f = g(c) * (d % y);
    ll s = g(d / y) * (y - (d % y));
    h -= f;
    h -= s;
    h += m;
    return h > 0;
}

void solve() {
    ll h, d;
    cin >> h >> d;
    ll l = 0;
    ll r = 1e15;
    ll ans = r;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (valid(mid, h, d)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans + d << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
