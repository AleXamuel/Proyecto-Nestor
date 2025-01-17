//https://codeforces.com/contest/2056/problem/B
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
#define MAXN 100000

vector<vector<int>> adj;
stack<int> Q;
vector<int> Toposort;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for (const auto &v : adj[u])
        if (!visited[v])
            dfs(v);
    Q.push(u);
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        adj.assign(n, vector<int>());
        fori(i, 0, n)
        {
            string s;
            cin >> s;
            fori(j, 0, n)
            {
                if (s[j] == '1' && j > i)
                    adj[i].push_back(j);
            }
        }
        visited.assign(n, false);
        fori(u, 0, n)
          if (!visited[u])
            dfs(u);
        while (!Q.empty())
        {
            Toposort.push_back(Q.top());
            Q.pop();
        }

        for (const auto &i : Toposort)
            cout << i+1 << " ";
        Toposort.clear();
        cout << ln;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
