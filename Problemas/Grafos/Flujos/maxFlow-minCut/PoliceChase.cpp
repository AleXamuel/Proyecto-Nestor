//https://cses.fi/problemset/task/1695
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
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pcc = pair<char, char>;
 
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);
 
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
 
const int MAXN = 500;
int n;
int capacity[MAXN][MAXN];
vector<int> adj[MAXN];
 
int bfs(int s, int t, VI &parent) {
    fill(all(parent), -1);
    parent[s] = -2;
    queue<pii> q;
    q.push({s, INF});
 
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
 
        for (int next: adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
 
int maxflow(int s, int t) {
    int flow = 0;
    VI parent(n);
    int new_flow;
 
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
 
void dfs(int u, bool vis[]) {
    vis[u] = true;
    for (int v: adj[u]) {
        if (!vis[v] && capacity[u][v] > 0)
            dfs(v, vis);
    }
}
 
void solve() {
    int m;
    cin >> n >> m;
 
    memset(capacity, 0, sizeof(capacity));
    For(i, 0, n)
        adj[i].clear();
 
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = 1;
        capacity[b][a] = 1;
    }
 
    int s = 0, t = n - 1;
    int min_cut = maxflow(s, t);
    cout << min_cut << ln;
    bool vis[MAXN] = {false};
    dfs(s, vis);
    For(u, 0, n) {
        for (int v: adj[u]) {
            if (vis[u] && !vis[v])
                cout << u + 1 << " " << v + 1 << ln;
        }
    }
    cout << ln;
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
	/*
	 * A minimum cut can be found after performing a maximum flow computation using
	 * the Ford-Fulkerson method. One possible minimum cut is the following: the set
	 * of all the vertices that can be reached from S in the residual graph (using
	 * edges with positive residual capacity), and the set of all the other
	 * vertices. This partition can be easily found using DFS starting at S .
	 */
