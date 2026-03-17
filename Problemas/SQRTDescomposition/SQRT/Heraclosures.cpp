//https://codeforces.com/gym/105505/problem/H
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
#define Vvi vector<vector<int>>
#define sz(A) (int)A.size()
#define Vi vector<ll>
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const int MAX = 8e3 + 2, MOD = 1e9 + 7, MOD2 = 1202773163, INF = 1e9, base = 29;
vector<int> adj[MAX];
int B = 150, n, m, A[MAX],AA[MAX], C[MAX][MAX], ans[MAX];

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return x * 1LL * y % MOD;
}

int calc(int i, int j) {
    int &ans = C[i][j];
    if (ans >= 0)
        return ans;
    ans = 0;
    for (int v: adj[i])
        ans = add(ans, calc(v, j));
    return ans;
}

int f(int u) {
    int &c = ans[u];
    if (c >= 0)
        return c;
    c = A[u];
    for (int v: adj[u])
        c = add(c, f(v));
    return c;
}

void solve() {
    cin >> n;
    memset(C, -1, sizeof(C));
    memset(ans, -1, sizeof(ans));
    For(i, 0, n) {
        cin >> A[i];
        AA[i]=A[i];
        C[i][i] = 1;
    }
    cin >> m;
    For(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    For(i, 0, n)
        For(j, 0, n)
            if (C[i][j] == -1)
                calc(i, j);
    For(i, 0, n)
        f(i);
    int q;
    cin >> q;
    vector<int> Q;
    vector<Pair > P;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int idx;
            cin >> idx;
            idx--;
            int r = ans[idx];
            for (auto [v,val]: P) {
                r = add(r, mul(val-A[v], C[idx][v]));
                A[v]=val;
            }
            for(auto[v,val]:P)
                A[v]=AA[v];
            Q.pb(r);
        } else {
            int u, val;
            cin >> u >> val;
            u--;
            P.pb({u, val});
            if (P.size() > B) {
                for (auto [a,b]: P) {
                    A[a] = b;
                    AA[a]=b;
                }
                memset(ans, -1, sizeof(ans));
                For(i, 0, n)
                    f(i);
                P.clear();
            }
        }
    }
    int r=0;
    For(i,0,Q.size()) {
        r=add(r,mul(Q[i],i+1));
    }
    cout<<r<<ln;

}

signed main() {
    //freopen("feast.in", "r",stdin);
    //freopen("feast.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
