//https://cses.fi/problemset/task/2104/
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MOD = 1000000007;
const ll inf = -2e18;
//solution
vector<int> sort_cyclic_shifts(string const &s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    s.pop_back();
    return sorted_shifts;
}

vector<int> p;

class ST {
private:
    vector<ll> t;
    int n;

    void buildST(vector<int> &a, int v, int tl, int tr) {
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
            t[v] = min(new_val, t[v]);
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
    ST(vector<int> &a) {
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

int f(int i, string &s, string &t) {
    For(j, 0, t.size()) {
        if (s[i] > t[j])
            return -1;
        if (s[i++] < t[j])
            return 1;
    }
    return 0;
}

int bs(string &s, string &t) {
    int ans = -2, l = 0, r = p.size() - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        int c = f(p[mid], s, t);
        if (c == 0)ans = mid;
        if (c <= 0)r = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}

int bs2(string &s, string &t) {
    int ans = -2, l = 0, r = p.size() - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        int c = f(p[mid], s, t);
        if (c == 0)ans = mid;
        if (c >= 0)l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    p = suffix_array_construction(s);
    ST sgt(p);
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int l = bs(s, t), r = bs2(s, t);
        if (l == -2) {
            cout << -1 << ln;
            continue;
        }
        cout << sgt.query(l, r) + 1 << ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti = 1;
    while (ti--) {
        solve();
    }
    return 0;
}
