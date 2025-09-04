//https://codeforces.com/contest/2114/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<int,int>

struct pt {
    ll x, y;
};

struct cmp_x {
    bool operator()(const pt &a, const pt &b) const {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
};

struct cmp_y {
    bool operator()(const pt &a, const pt &b) const {
        if (a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    }
};


ostream &operator<<(ostream &os, const pt &a) {
    return os << "(" << a.x << "," << a.y << ")";
}

int n;
set<pt, cmp_x> X;
set<pt, cmp_y> Y;

ll area() {
    pt a1 = *X.begin();
    pt a2 = *X.rbegin();
    pt b1 = *Y.begin();
    pt b2 = *Y.rbegin();
    return (a2.x - a1.x + 1) * (b2.y - b1.y + 1);
}

ll ans(const pt &cur) {
    X.erase(cur);
    Y.erase(cur);
    ll res = area();
    if (res == n - 1) {
        pt a1 = *X.begin();
        pt a2 = *X.rbegin();
        pt b1 = *Y.begin();
        pt b2 = *Y.rbegin();
        X.insert(cur);
        Y.insert(cur);
        return res + min(b2.y - b1.y + 1, a2.x - a1.x + 1);
    }
    X.insert(cur);
    Y.insert(cur);
    return res;
}

void solve() {
    X.clear();
    Y.clear();
    cin >> n;
    For(i, 0, n) {
        pt p;
        cin >> p.x >> p.y;
        X.insert(p);
        Y.insert(p);
    }
    if (n == 1) {
        cout << 1 << ln;
        return;
    }
    cout << min({ans(*X.begin()), ans(*X.rbegin()), ans(*Y.begin()), ans(*Y.rbegin())}) << ln;
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
