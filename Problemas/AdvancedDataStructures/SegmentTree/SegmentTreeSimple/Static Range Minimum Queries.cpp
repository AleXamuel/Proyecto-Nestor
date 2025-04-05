//https://cses.fi/problemset/result/12087849/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200000;

int t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int get_min(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INT_MAX;
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(
        get_min(v * 2, tl, tm, l, min(r, tm)),
        get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
    );
}

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int res = get_min(1, 0, n - 1, l, r);
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
