//https://cses.fi/problemset/result/12078785/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN 200001
int n;
ll t[4 * MAXN];
ll lazy[4 * MAXN];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2 + 1]);
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        t[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void updateRange(int v, int tl, int tr, int l, int r, ll u) {
    push(v, tl, tr);
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
        lazy[v] += u;
        push(v, tl, tr);
    } else {
        int tm = (tl + tr) / 2;
        updateRange(v * 2, tl, tm, l, r, u);
        updateRange(v * 2 + 1, tm + 1, tr, l, r, u);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll query(int v, int tl, int tr, int pos) {
    push(v, tl, tr);  
    if (tl == tr) 
        return t[v];  
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return query(v * 2, tl, tm, pos);
    return query(v * 2 + 1, tm + 1, tr, pos);
}

void solve() {
    int q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n-1);
    while (q--) {
        int m;
        cin >> m;
        if (m == 2) {
            int k;
            cin >> k;
            k--;
            cout <<query(1, 0, n-1, k) << endl;
        }
        else {
            int l, r;
            ll u;
            cin >> l >> r >> u;
            l--, r--;
            updateRange (1, 0, n-1, l, r, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
