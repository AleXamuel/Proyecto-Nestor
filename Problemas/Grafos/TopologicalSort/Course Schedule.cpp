//https://cses.fi/problemset/task/1679
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

const int MAX = 1e5;
int n;

vector<int> adj[MAX];
int state[MAX];
stack<int> Q;

bool dfs(int u) {
    state[u] = 1;
    bool ans = false;
    for (const auto &v: adj[u]) {
        if (state[v] == 0)
            ans = ans || dfs(v);
        else if (state[v] == 1)
            return true;
    }
    Q.push(u);
    state[u] = 2;
    return ans;
}


void solve() {
    int m;
    cin >> n >> m;
    For(i, 0, n)
        state[i] = 0;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    For(u, 0, n)
        if (state[u] == 0 && dfs(u)) {
            cout << "IMPOSSIBLE" << ln;
            return;
        }
    while (!Q.empty()) {
        cout << Q.top() + 1 << " ";
        Q.pop();
    }
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
