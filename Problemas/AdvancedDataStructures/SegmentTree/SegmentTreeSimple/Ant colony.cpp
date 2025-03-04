//https://codeforces.com/contest/474/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

ll n, t_gcd[4*MAXN], t_min[4*MAXN];
ll a[MAXN];
map<int, vector<int>> pos;

void build_gcd(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t_gcd[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_gcd(a, v*2, tl, tm);
        build_gcd(a, v*2+1, tm+1, tr);
        t_gcd[v] = __gcd(t_gcd[v*2], t_gcd[v*2+1]);
    }
}

void build_min(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t_min[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_min(a, v*2, tl, tm);
        build_min(a, v*2+1, tm+1, tr);
        t_min[v] = min(t_min[v*2], t_min[v*2+1]);
    }
}

ll query_gcd(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t_gcd[v];
    }
    int tm = (tl + tr) / 2;
    ll p1 = query_gcd(v*2, tl, tm, l, min(r, tm));
    ll p2 = query_gcd(v*2+1, tm+1, tr, max(l, tm+1), r);
    return __gcd(p1, p2);
}

ll query_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return LLONG_MAX;
    if (l == tl && r == tr) {
        return t_min[v];
    }
    int tm = (tl + tr) / 2;
    ll p1 = query_min(v*2, tl, tm, l, min(r, tm));
    ll p2 = query_min(v*2+1, tm+1, tr, max(l, tm+1), r);
    return min(p1, p2);
}

int count_values(int val, int l, int r) {
    if (!pos.count(val)) return 0;
    const vector<int>& vec = pos[val];
    auto it1 = lower_bound(vec.begin(), vec.end(), l);
    auto it2 = upper_bound(vec.begin(), vec.end(), r);
    return it2 - it1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    build_gcd(a, 1, 0, n-1);
    build_min(a, 1, 0, n-1);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        ll gcd_val = query_gcd(1, 0, n-1, l, r);
        ll min_val = query_min(1, 0, n-1, l, r);

        if (gcd_val == min_val) {
            int count = count_values(gcd_val, l, r);
            cout << (r - l + 1 - count) << '\n';
        } else {
            cout << (r - l + 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
