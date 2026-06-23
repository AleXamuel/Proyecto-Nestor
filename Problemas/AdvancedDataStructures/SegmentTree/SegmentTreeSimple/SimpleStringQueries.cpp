//https://atcoder.jp/contests/abc157/tasks/abc157_e
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define ones(x) __builtin_popcount(x)
#define VI vector<int>
#define VVI vector<VI>
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(), (v).end()
#define ln "\n"

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pcc = pair<char, char>;

const int maxn = 500000 + 1;

class ST {
    vector<int> t;
    int n;

    void buildST(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] | t[v * 2 + 1];
        }
    }

    int queryST(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return queryST(v * 2, tl, tm, l, min(r, tm)) |
               queryST(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void updateST(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) updateST(v * 2, tl, tm, pos, new_val);
            else updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] | t[v * 2 + 1];
        }
    }

public:
    ST(vector<int> &a) {
        n = a.size();
        t.assign(4 * n, 0);
        buildST(a, 1, 0, n - 1);
    }

    int query(int l, int r) {
        return queryST(1, 0, n - 1, l, r);
    }

    void update(int pos, int x) {
        updateST(1, 0, n - 1, pos, x);
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int q;
    cin >> q;

    VI A(n);
    For(i, 0, n) {
        A[i] = 1 << (s[i] - 'a');
    }

    ST st(A);

    For(i, 0, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            st.update(pos, 1 << (c - 'a'));
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << ones(st.query(l, r)) << ln;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}
