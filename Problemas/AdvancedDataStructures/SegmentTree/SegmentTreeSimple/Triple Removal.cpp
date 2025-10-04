//https://codeforces.com/contest/2152/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, sz(A)-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}

class ST {
public:
    vector<int> t;
    int n;

    int combine(int a, int b) {
        return min(a, b);
    }

    void buildST(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 1e8;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                       query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void updateST(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateST(v * 2, tl, tm, pos, new_val);
            else
                updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    ST(vector<int> &a) {
        n = a.size();
        if (n == 0)
            return;
        t.resize(4 * n);
        buildST(a, 1, 0, n - 1);
    }

    ST(int sz) {
        n = sz;
        t.assign(4 * n, 0);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int pos, int x) {
        updateST(1, 0, n - 1, pos, x);
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    vector<int> pref0(n);
    vector<int> pref1(n);
    pref0[0] = A[0] == 0;
    pref1[0] = A[0] == 1;
    vector<int> pos0;
    vector<int> pos1;
    For(i, 1, n) {
        if (A[i] == 0) {
            pref0[i] = pref0[i - 1] + 1;
            pref1[i] = pref1[i - 1];
            pos0.push_back(i);
        } else {
            pref1[i] = pref1[i - 1] + 1;
            pref0[i] = pref0[i - 1];
            pos1.push_back(i);
        }
    }

    unordered_map<int, int> mp1;
    vector<int> difs0;
    For(i, 0, sz(pos0)-1) {
        difs0.push_back(pos0[i + 1] - pos0[i]);
        mp1[pos0[i]] = i;
    }
    if (sz(pos0))
        mp1[pos0.back()] = sz(pos0) - 1;

    unordered_map<int, int> mp2;
    vector<int> difs1;
    For(i, 0, sz(pos1)-1) {
        difs1.push_back(pos1[i + 1] - pos1[i]);
        mp2[pos1[i]] = i;
    }
    if (sz(pos1))
        mp2[pos1.back()] = sz(pos1) - 1;

    ST T1 = ST(difs0);
    ST T2 = ST(difs1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int cnt0 = pref0[r] - (l == 0 ? 0 : pref0[l - 1]);
        int cnt1 = pref1[r] - (l == 0 ? 0 : pref1[l - 1]);
        if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
            cout << -1 << ln;
            continue;
        }
        int ans1 = 1e9;
        if (cnt0) {
            int L = *lower_bound(all(pos0), l);
            auto it = upper_bound(all(pos0), r);
            --it;
            int R = *it;
            int dif = T1.query(mp1[L], mp1[R] - 1);
            ans1 = dif + ((cnt0 - 3) / 3) + (cnt1 / 3);
        }
        int ans2 = 1e9;
        if (cnt1) {
            int L = *lower_bound(all(pos1), l);
            auto it = upper_bound(all(pos1), r);
            --it;
            int R = *it;
            int dif = T2.query(mp2[L], mp2[R] - 1);
            ans2 = dif + ((cnt1 - 3) / 3) + (cnt0 / 3);
        }
        cout << min(ans1, ans2) << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
