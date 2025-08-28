//https://codeforces.com/contest/2134/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

const int MAX = 2e5;

vector<int> adj[MAX];
int pi[MAX];
int n;
int maxVertex, maxDepth;
bool diametro[MAX];


void dfs(int u, int par, int depth) {
    if (depth > maxDepth) {
        maxVertex = u;
        maxDepth = depth;
    }
    pi[u] = par;
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        dfs(v, u, depth + 1);
    }
}

int deg(int u) {
    return (int) adj[u].size();
}

void solve() {
    cin >> n;
    For(i, 0, n) {
        adj[i].clear();
        pi[i] = -1;
        diametro[i] = false;
    }
    For(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxVertex = 0;
    maxDepth = 0;
    dfs(0, -1, 0);
    maxDepth = 0;
    dfs(maxVertex, -1, 0);
    while (maxVertex != -1) {
        diametro[maxVertex] = true;
        maxVertex = pi[maxVertex];
    }
    For(u, 0, n)
        if (diametro[u] && deg(u) >= 3) {
            int a = pi[u];
            for (const auto &v: adj[u])
                if (v != a && !diametro[v]) {
                    cout << a + 1 << " " << u + 1 << " " << v + 1 << ln;
                    return;
                }
        }
    cout << -1 << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
