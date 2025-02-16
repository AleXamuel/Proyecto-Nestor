
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
class ST {
private:
    vector<ll> t;
    int n;

    void buildST(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll sumST(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 1e18;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return min(sumST(v * 2, tl, tm, l, min(r, tm)),
                   sumST(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void updateST(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            t[v] = min(new_val,t[v]);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateST(v * 2, tl, tm, pos, new_val);
            else
                updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
        buildST(a, 1, 0, n - 1);
    }

    ll query(int l, int r) {
        return sumST(1, 0, n - 1, l, r);
    }

    void update(int pos, int x) {
        updateST(1, 0, n - 1, pos, x);
    }
};
