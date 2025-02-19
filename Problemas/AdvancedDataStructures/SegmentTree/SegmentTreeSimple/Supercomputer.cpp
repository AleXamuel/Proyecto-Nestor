//https://open.kattis.com/submissions/15482226
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] ^= 1;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve() {
    int q;
    cin >> n >> q;
    int a[n] = {0};
    build (a, 1, 0, n-1);
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == 'C') {
           int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n-1, l, r) << endl;
        }
        else {
            int idx;
            cin >> idx;
            idx--;
            update(1, 0, n-1, idx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
