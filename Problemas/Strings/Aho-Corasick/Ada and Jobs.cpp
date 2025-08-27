//https://vjudge.net/problem/SPOJ-ADAJOBS
#include <bits/stdc++.h>
using namespace std;
#define dll long double
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const int nmax = 2e6 + 1, mod = 998244353, inf = 1e9;

struct Aho {
    static constexpr int K = 52;
    int n, rt, chd[nmax][K], fail[nmax], q[nmax], hd, tl, en[nmax];

    int newNode() {
        n++;
        fill_n(chd[n], K, 0);
        fail[n] = 0;
        en[n] = inf;
        return n;
    }

    void init() {
        n = 0;
        rt = newNode();
        fail[rt] = rt;
    }

    int get(char c) {
        return c < 'a' ? c + 26 - 'A' : c - 'a';
    }

    void insert(string &s, int k) {
        int u, i, c;
        int sn = s.size();
        u = rt;
        for (i = 0; i < sn; i++) {
            c = get(s[i]);
            if (!chd[u][c])
                chd[u][c] = newNode();
            u = chd[u][c];
        }
        en[u] = min(en[u], k);
    }

    void build() {
        int c, u, v, w;
        hd = tl = 0;
        for (c = 0; c < K; c++) {
            u = chd[rt][c];
            if (!u)continue;
            fail[u] = rt;
            q[tl++] = u;
        }
        while (hd < tl) {
            u = q[hd++];
            en[u] = min(en[u], en[fail[u]]);
            for (c = 0; c < K; c++) {
                v = chd[u][c];
                if (!v)continue;
                for (w = fail[u]; w != rt && !chd[w][c]; w = fail[w]);
                if (chd[w][c])w = chd[w][c];
                fail[v] = w;
                q[tl++] = v;
            }
        }
    }

    int find(string &s) {
        int len = s.length();
        int u = rt;
        int ans = inf;
        for (int i = 0; i < len; i++) {
            int c = get(s[i]);
            while (u != rt && !chd[u][c])
                u = fail[u];
            if (chd[u][c])
                u = chd[u][c];
            ans = min(ans, en[u]);
        }
        return ans;
    }
};

Aho ah;

void solve() {
    ah.init();
    int q;
    cin >> q;
    vector<pair<string, int> > ans;
    For(i, 0, q) {
        int k;
        string s;
        cin >> k >> s;
        if (k & 1)
            ans.eb(s, i);
        else
            ah.insert(s, i);
    }
    ah.build();
    for (auto &[s,j]: ans)
        if (ah.find(s) < j)
            cout << "YES" << ln;
        else
            cout << "NO" << ln;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
