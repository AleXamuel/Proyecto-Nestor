//https://cses.fi/problemset/result/12087918/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200000;

ll t[4 * MAXN];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n-1);
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int k;
            ll u;
            cin >> k >> u;
            k--;
            update(1, 0, n-1, k, u);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sum(1, 0, n-1, l, r) << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
