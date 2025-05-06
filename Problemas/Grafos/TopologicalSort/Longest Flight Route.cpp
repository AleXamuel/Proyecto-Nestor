//https://cses.fi/problemset/task/1680/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long
#define size(l,r) (r-l+1)
const int MAXN = 200001;

vector<int> adj[MAXN];
bool visited[MAXN];
stack<int> topSort;

void dfs(int u) {
    visited[u] = true;
    for (const auto &v: adj[u])
        if (!visited[v])
            dfs(v);
    topSort.push(u);
}

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    dfs(0);
    if (!visited[n - 1]) {
        cout << "IMPOSSIBLE" << ln;
        return;
    }
    vector<int> d(n, 0);
    vector<int> pi(n, -1);
    while (!topSort.empty()) {
        int u = topSort.top();
        topSort.pop();
        for (const auto &v: adj[u])
            if (d[u] + 1 > d[v]) {
                d[v] = d[u] + 1;
                pi[v] = u;
            }
    }
    deque<int> path;
    int t = n - 1;
    while (t != -1) {
        path.push_front(t);
        t = pi[t];
    }
    cout << d[n - 1] + 1 << ln;
    for (const auto &i: path)
        cout << i + 1 << " ";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
