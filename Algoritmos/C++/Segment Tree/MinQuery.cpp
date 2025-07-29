#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
class ST {
    vector<int> t;
    int n;
    int combine(int a, int b) {
        return max(a,b);
    }
    void buildST(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    int sumST(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -2e9;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(sumST(v * 2, tl, tm, l, min(r, tm)),
                   sumST(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void updateST(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] =new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateST(v * 2, tl, tm, pos, new_val);
            else
                updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    ST(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
        buildST(a, 1, 0, n - 1);
    }
    int query(int l, int r) {
        return sumST(1, 0, n - 1, l, r);
    }
    void update(int pos, int x) {
        updateST(1, 0, n - 1, pos, x);
    }
};
