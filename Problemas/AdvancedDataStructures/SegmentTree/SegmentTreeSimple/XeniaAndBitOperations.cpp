//https://codeforces.com/contest/339/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN (1 << 17)

int n;
ll t[4 * MAXN];

bool isOrLevel(int level) {
    return level % 2 == 1;
}

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);

    int height = 31 - __builtin_clz(tr - tl + 1); // altura donde esta el numero ubicado en el arbol 
    if (isOrLevel(height)) {
        t[v] = t[v * 2] | t[v * 2 + 1];
    } else {
        t[v] = t[v * 2] ^ t[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
        return;
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
    else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);

    int height = 31 - __builtin_clz(tr - tl + 1);
    if (isOrLevel(height)) {
        t[v] = t[v * 2] | t[v * 2 + 1];
    } else {
        t[v] = t[v * 2] ^ t[v * 2 + 1];
    }
}

void solve() {
    int m;
    cin >> n >> m;
    ll a[1<<n];
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }

    build(a, 1, 0, (1 << n) - 1);

    for (int i = 0; i < m; i++) {
        int p;
        ll b;
        cin >> p >> b;
        update(1, 0, (1 << n) - 1, p - 1, b);
        cout << t[1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
