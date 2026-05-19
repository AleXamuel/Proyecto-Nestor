//https://codeforces.com/contest/2228/problem/D
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l, r)(rng);
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl;
#define RAYA cerr << " ============================ " << endl;


struct pt {
    int x, y;

    bool operator<(const pt &o) const {
        if (x != o.x)
            return x < o.x;
        return y < o.y;
    }
};

ostream &operator<<(ostream &os, const pt &a) {
    return os << "(" << a.x << "," << a.y << ")";
}


void solve() {
    int n;
    cin >> n;
    vector<int> x, y;
    vector<pt> A(n);
    For(i, 0, n) {
        cin >> A[i].x >> A[i].y;
        x.push_back(A[i].x);
        y.push_back(A[i].y);
    }
    sort(all(A));
    vector<int> pref_max(n), pref_min(n), suf_max(n), suf_min(n);
    pref_max[0] = A[0].y;
    pref_min[0] = A[0].y;

    For(i, 1, n) {
        pref_max[i] = max(pref_max[i - 1], A[i].y);
        pref_min[i] = min(pref_min[i - 1], A[i].y);
    }

    suf_max[n - 1] = A[n - 1].y;
    suf_min[n - 1] = A[n - 1].y;
    Rfor(i, n-2, 0) {
        suf_max[i] = max(suf_max[i + 1], A[i].y);
        suf_min[i] = min(suf_min[i + 1], A[i].y);
    }

    ll ans = 0;
    sort(all(x));
    sort(all(y));
    x.erase(unique(all(x)), x.end());
    y.erase(unique(all(y)), y.end());
    x.pop_back();

    for (const auto &X: x) {
        int i = upper_bound(all(A), pt{X, INT_MAX}) - A.begin() - 1;
        int a = pref_max[i];
        int b = pref_min[i];
        assert(i+1<n);
        int c = suf_max[i + 1];
        int d = suf_min[i + 1];

        int l = upper_bound(all(y), max(b, d)) - y.begin();
        int r = upper_bound(all(y), min(a, c)) - y.begin();
        ans += max(0, r - l);
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
