//https://www.spoj.com/problems/CANDN/
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define MAXN 1000001

vector<vector<pair<int, int>>> adj;
int n;
const int INF = INT_MAX;
vector<int> dijkstra(int s)
{
    vector<int> d(n, INF);
    vector<bool> visited(n, false);
    d[s] = 0;
    set<pair<int, int>> Q;
    Q.insert({d[s], s});
    while (!Q.empty())
    {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        if (visited[u])
            continue;
        visited[u] = true;
        for (const auto &ee : adj[u])
        {
            int v = ee.first;
            int w = ee.second;
            if (!visited[v] && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                Q.insert({d[v], v});
            }
        }
    }
    return d;
}

void solve()
{
    while (true)
    {
        int B, C, N, m;
        cin >> n >> B >> C >> N >> m;
        if (n == -1)
            break;
        B--;
        C--;
        N--;
        adj.assign(n, vector<pair<int, int>>());
        fori(i, 0, m)
        {
            int a, b, w;
            cin >> a >> b >> w;
            a--;
            b--;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        vector<int> bar = dijkstra(B);
        vector<int> carlos = dijkstra(C);
        vector<int> nico = dijkstra(N);
        int ans = 0;
        fori(u, 0, n)
            if (bar[u] + carlos[u] == bar[C] && bar[u] + nico[u] == bar[N])
                ans = max(ans, bar[u]);
        cout << ans << " " << bar[C] - ans << " " << bar[N] - ans << ln;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
