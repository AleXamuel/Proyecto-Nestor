//https://cses.fi/problemset/task/1687
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

const int MAXN = 200005;
const int LOG = 20;
VI adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
int n, q;

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (parent[u][i - 1] != -1)
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }

    for (int v: adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int binaryLifting(int u, int x) {
    for (int i = 0; i < LOG; i++)
        if (x & (1 << i)) {
            if (u == -1) return -1;
            u = parent[u][i];
        }
    return u;
}

void solve() {
    int n, q;
    cin >> n >> q;

    For(i,0, n){
        adj[i].clear();
        depth[i] = 0;
        For(j, 0, LOG)
            parent[i][j] = -1;
    }

    For(a, 1, n) {
        int b;
        cin >> b;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[0] = 0;
    dfs(0, -1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        int ans = binaryLifting(x, k);
        if (ans == -1)
            cout << -1 << ln;
        else
            cout << ans + 1 << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
