//https://vjudge.net/problem/SPOJ-POLQUERY
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l, r)(rng);
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define pb push_back
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl
#define RAYA cerr << " ============================ " << endl

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int d[MAX], low[MAX], dp[MAX][20], pi[MAX], n;
bool ap[MAX];

set<Pair > bridges;

void preprocess() {
    For(u, 0, n)
        dp[u][0] = pi[u];

    For(j, 1, 20)
        For(u, 0, n)
            dp[u][j] = dp[dp[u][j - 1]][j - 1];
}

int binaryLifting(int u, int x) {
    For(i, 0, 20)
        if (x >> i & 1)
            u = dp[u][i];
    return u;
}

int lca(int a, int b) {
    int h1 = d[a];
    int h2 = d[b];
    if (h1 > h2) {
        swap(a, b);
        swap(h1, h2);
    }
    b = binaryLifting(b, h2 - h1);
    if (a == b)
        return a;
    Rfor(i, 19, 0) {
        if (dp[a][i] == dp[b][i])
            continue;
        a = dp[a][i];
        b = dp[b][i];
    }
    return pi[a];
}

void dfs(int u, int par) {
    low[u] = d[u];
    pi[u] = par;
    int child = 0;
    for (const int &v: adj[u]) {
        if (v == par)
            continue;
        if (d[v] == -1) {
            child++;
            d[v] = d[u] + 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > d[u])
                bridges.insert({max(u, v), min(u, v)});
            if (u != 0 && low[v] >= d[u])
                ap[u] = true;
        } else {
            low[u] = min(low[u], d[v]);
        }
    }
    if (child > 1 && u == 0)
        ap[u] = true;
}

void solve() {
    int m;
    cin >> n >> m;
    For(i, 0, n) {
        d[i] = -1;
        low[i] = -1;
        pi[i] = 0;
        ap[i] = false;
    }
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    d[0] = 1;
    dfs(0, 0);
    preprocess();
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (u < v)
                swap(u, v);
            if (bridges.find({u, v}) == bridges.end()) {
                cout << "da" << ln;
                continue;
            }
            if (d[u] < d[v])
                swap(u, v);
            if (max(d[a], d[b]) < d[u]) {
                cout << "da" << ln;
                continue;
            }
            int l1 = lca(a, u);
            int l2 = lca(b, u);
            if (l1 == l2 || (l1 != u && l2 != u))
                cout << "da" << ln;
            else
                cout << "ne" << ln;
        } else {
            int u;
            cin >> u;
            u--;
            if (!ap[u] || max(d[a], d[b]) < d[u]) {
                cout << "da" << ln;
                continue;
            }
            int l = lca(a, b);
            if (d[l] > d[u]) {
                cout << "da" << ln;
                continue;
            }
            int l1 = lca(a, u);
            int l2 = lca(b, u);
            if (l1 != u && l2 != u) {
                cout << "da" << ln;
                continue;
            }
            int suba = binaryLifting(a, d[a] - d[u] - 1);
            int subb = binaryLifting(b, d[b] - d[u] - 1);
            if (l == u) {
                if (low[suba] < d[u] && low[subb] < d[u])
                    cout << "da" << ln;
                else
                    cout << "ne" << ln;
            } else if (l1 == u) {
                if (low[suba] < d[u])
                    cout << "da" << ln;
                else
                    cout << "ne" << ln;
            } else {
                if (low[subb] < d[u])
                    cout << "da" << ln;
                else
                    cout << "ne" << ln;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w",stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
