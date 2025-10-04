//https://codeforces.com/contest/2152/problem/B
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

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}

ll n, x_1, y_1, x_2, y_2;

bool valid(ll m) {
    ll min_x = max(0ll, x_1 - m);
    ll max_x = min(x_1 + m, n);
    ll min_y = max(0ll, y_1 - m);
    ll max_y = min(y_1 + m, n);

    return max(0ll, x_2 - m) <= min_x && min(x_2 + m, n) >= max_x
           && max(0ll, y_2 - m) <= min_y && min(y_2 + m, n) >= max_y;
}


void solve() {
    cin >> n >> x_1 >> y_1 >> x_2 >> y_2;
    ll l = 1;
    ll r = 1e15;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
    return 0;
}
