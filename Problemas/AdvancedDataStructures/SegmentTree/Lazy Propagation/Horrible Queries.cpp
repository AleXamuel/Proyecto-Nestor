//https://vjudge.net/problem/SPOJ-HORRIBLE
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll *t, *lazy;
void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        int tm = (tl + tr) / 2;
        t[v * 2] += lazy[v] * (tm - tl + 1);
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v] * (tr - tm);
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r) return;
    if (l == tl && tr == r) {
        t[v] += addend * (tr - tl + 1);
        lazy[v] += addend;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && tr == r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti;
    cin >> ti;
    while (ti--) {
        int n, q;
        cin >> n >> q;
        ll* a = new ll[n]();
        t = new ll[4 * n]();
        lazy = new ll[4 * n]();
        build(a, 1, 0, n - 1);
        for (int i = 0; i < q; i++) {
            int k;
            cin >> k;
            if (k == 1) {
                int l, r;
                cin >> l >> r;
                cout << query(1, 0, n - 1, l - 1, r - 1) << " ";
            } else {
                int l, r;
                ll x;
                cin >> l >> r >> x;
                update(1, 0, n - 1, l - 1, r - 1, x);
            }
        }
        cout << "\n";
        delete[] a;
        delete[] t;
        delete[] lazy;
    }
    return 0;
}
