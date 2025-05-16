//https://cses.fi/problemset/task/1666/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 100001;
vector<int> adj[MAXN];
bool visited[MAXN];
int n;

void bfs(int s) {
    queue<int> Q;
    visited[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (const auto &v: adj[u])
            if (!visited[v]) {
                visited[v] = true;
                Q.push(v);
            }
    }
}

void solve() {
    int m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int, int> > ans;
    int prev = -1;
    For(u, 0, n)
        if (!visited[u]) {
            bfs(u);
            if (prev == -1)
                prev = u;
            else {
                ans.emplace_back(prev, u);
                prev = u;
            }
        }
    cout << ans.size() << ln;
    for (const auto &e: ans)
        cout << e.first + 1 << " " << e.second + 1 << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
