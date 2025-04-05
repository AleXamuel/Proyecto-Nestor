//https://vjudge.net/problem/SPOJ-KQUERY
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 30005;
const int MOD = 1000000007;

vector<int> t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int k) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v].end() - upper_bound(t[v].begin(), t[v].end(), k);
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm), k) +
           query(v*2+1, tm+1, tr, max(l, tm+1), r, k);
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n-1);
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        cout << query(1, 0, n - 1, l, r, k) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
