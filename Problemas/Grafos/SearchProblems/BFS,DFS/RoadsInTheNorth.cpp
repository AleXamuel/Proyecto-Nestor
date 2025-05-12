//https://vjudge.net/problem/UVA-10308
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 10005;


vector<pair<int,ll> > adj[MAXN];
bool visited[MAXN];

ll max_cost;
int max_vertex;

void dfs(int u,ll cost) {
    visited[u] = true;
    if (cost > max_cost) {
        max_cost = cost;
        max_vertex = u;
    }
    for (const auto &e: adj[u]) {
        int v = e.first;
        ll w = e.second;
        if (!visited[v]) {
            dfs(v, cost + w);
        }
    }
}


void solve() {
    string in;
    while (getline(cin, in)) {
        if (in.empty()) {
            max_cost = 0;
            max_vertex = 0;
            dfs(0, 0);
            memset(visited, false, sizeof(visited));
            max_cost = 0;
            dfs(max_vertex, 0);
            cout << max_cost << ln;
            For(i, 0, MAXN) {
                adj[i].clear();
                visited[i] = false;
            }
        } else {
            stringstream ss(in);
            int a, b;
            ll w;
            ss >> a >> b >> w;
            a--;
            b--;
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }
    }
    max_cost = 0;
    max_vertex = 0;
    dfs(0, 0);
    memset(visited, false, sizeof(visited));
    max_cost = 0;
    dfs(max_vertex, 0);
    cout << max_cost << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
