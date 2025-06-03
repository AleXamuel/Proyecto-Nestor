//https://codeforces.com/gym/101889/attachments problem M
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<ll,int>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1000000007;
const int inf = 500;
//solution
vector<int> sort_cyclic_shifts(vector<int> const &s) {
    int n = s.size();
    const int alphabet = 501;
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

vector<int> suffix_array_construction(vector<int> &s) {
    s.pb(0);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> start, p, at;

struct marble {
    int val, pile, idx;

    bool operator<(const marble &b) const {
        if (val == b.val) {
            int pos = start[pile] + idx, bPos = start[b.pile] + b.idx;
            return at[pos] < at[bPos];
        }
        return val < b.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    For(i, 0, n) {
        start.pb(a.size());
        int m;
        cin >> m;
        For(j, 0, m) {
            int x;
            cin >> x;
            a.pb(x);
        }
        a.pb(inf);
    }
    at.resize(a.size());
    p = suffix_array_construction(a);
    For(i, 0, a.size())
        at[p[i]] = i;
    set<marble> st;
    For(i, 0, n)
        st.insert({a[start[i]], i, 0});
    vector<int> ans;
    while (!st.empty()) {
        marble m = *st.begin();
        st.erase(st.begin());
        ans.pb(m.val);
        int i = m.idx;
        if (a[start[m.pile] + i + 1] != inf)
            st.insert({a[start[m.pile] + i + 1], m.pile, i + 1});
    }
    ll c = 0;
    ll x = 365;
    Rfor(i, ans.size()-1, 0) {
        c += ans[i] * x;
        x *= 365;
        c %= mod;
        x %= mod;
    }
    cout << c << endl;
    return 0;
}
