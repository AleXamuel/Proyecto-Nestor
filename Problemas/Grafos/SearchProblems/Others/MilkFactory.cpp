//https://vjudge.net/problem/USACO-940
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
#define fori(i, k, n) for (int i = k; i < (n); i++)
#define MAXN 50000

vector<vector<int>> adj;
vector<bool> visited;
int n;

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v);
}

void solve()
{

    cin >> n;
    adj.assign(n, vector<int>());
    fori(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[b].push_back(a);
    }
    fori(i, 0, n)
    {
        visited.assign(n, false);
        dfs(i);
        bool ans = true;
        for (const auto &e : visited)
            if (!e)
            {
                ans = false;
                break;
            }
        if (ans)
        {
            cout << ++i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    solve();
    return 0;
}
