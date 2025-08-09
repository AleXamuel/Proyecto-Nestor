//https://cses.fi/problemset/task/1163/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"


struct range {
    ll l, r;
    ll len = r - l + 1;

    bool operator<(const range &o) const {
        if (l != o.l)
            return l < o.l;
        return r < o.r;
    }
};


ostream &operator<<(ostream &os, range &o) {
    return os << "(" << o.l << "," << o.r << ")";
}


void solve() {
    ll x, n;
    cin >> x >> n;
    set<range> Q;
    multiset<ll> ans;
    range s = {0, x - 1};
    Q.insert(s);
    ans.insert(s.len);
    For(i, 0, n) {
        ll pos;
        cin >> pos;
        auto it = Q.upper_bound({pos, pos});
        --it;
        range cur = *it;
        Q.erase(cur);
        ans.erase(ans.find(cur.len));
        range left = {cur.l, pos - 1};
        range right = {pos, cur.r};
        Q.insert(left);
        Q.insert(right);
        ans.insert(left.len);
        ans.insert(right.len);
        cout << *ans.rbegin() << " ";
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
