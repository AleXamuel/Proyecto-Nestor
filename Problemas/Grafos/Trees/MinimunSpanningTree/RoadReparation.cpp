//https://cses.fi/problemset/task/1675/
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#define PI acos(-1)
#define toRadians(angle) PI *angle / 180
#define toDegree(angle) (180 * angle) / PI
#define fori(i, k, n) for (int i = k; i < (n); i++)
#define MAXN 200000
#define ln "\n"

struct point
{
    long long x, y;
    point() {}
    point(long long x, long long y) : x(x), y(y) {}
};

const long long INF = LONG_MAX;
vector<vector<pair<int, long long>>> adj;
vector<bool> visited;
int n;

long long prim(int s)
{
    vector<long long> d(n, INF);
    visited.assign(n, false);
    d[s] = 0;
    set<pair<long long, int>> Q;
    Q.insert({d[s], s});
    while (!Q.empty())
    {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto ee : adj[u])
        {
            int v = ee.first;
            long long w = ee.second;
            if (!visited[v] && w < d[v])
            {
                d[v] = w;
                Q.insert({d[v], v});
            }
        }
    }
    long long total_cost = 0;
    for (const auto &c : d)
        total_cost += c;
    return total_cost;
}

void solve()
{
    int m;
    cin >> n >> m;
    adj.assign(n, vector<pair<int, long long>>());
    fori(i, 0, m)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    long long cost = prim(0);
    for (const auto &i : visited)
        if (!i)
        {
            cout << "IMPOSSIBLE" << ln;
            return;
        }
    cout << cost << ln;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
