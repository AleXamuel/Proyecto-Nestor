//https://codeforces.com/problemset/problem/1234/D
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, t[4*MAXN];

void build(const string& s, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 1 << (s[tl] - 'a');
        return;
    }
    int tm = (tl + tr) / 2;
    build(s, v * 2, tl, tm);
    build(s, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] | t[v * 2 + 1];
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) |
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, char new_char) {
    if (tl == tr) {
        t[v] = 1 << (new_char - 'a');
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v * 2, tl, tm, pos, new_char);
    else
        update(v * 2 + 1, tm + 1, tr, pos, new_char);
    t[v] = t[v * 2] | t[v * 2 + 1];
}

int countBits(int mask) {
    return __builtin_popcount(mask);
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    int q;
    cin >> q;
    build(s, 1, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            update(1, 0, n - 1, pos, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int mask = query(1, 0, n - 1, l, r);
            cout << countBits(mask) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
