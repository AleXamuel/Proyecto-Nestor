//https://atcoder.jp/contests/dp/tasks/dp_q

using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define MAXN 200001

int n;
long long A[MAXN], t[4 * MAXN];;

void build(long long a[], int v = 1, int tl = 0, int tr = n ) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, (v << 1) + 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) >> 1;
    return max(query(v << 1, tl, tm, l, min(r, tm)), query((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(v << 1, tl, tm, pos, new_val);
        else
            update((v << 1) + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }
}


void solve() {
    cin >> n;
    vector<int> H(n);
    vector<int> V(n);
    fori(i, 0, n)
        cin >> H[i];
    fori(i, 0, n)
        cin >> V[i];

    memset(A, 0, sizeof(A));
    A[H[n - 1]] = V[n - 1];
    build(A);
    for (int i = n - 2; i >= 0; i--) {
        int val = H[i];
        long long  q = query(1, 0, n, val, n);
        update(1, 0, n , val, V[i] + q);
    }
    cout << t[1] << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
