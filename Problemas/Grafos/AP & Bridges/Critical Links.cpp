//https://vjudge.net/problem/UVA-796
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(), A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

vector<vector<int> > adj;
vector<int> d, low;
int TIME;
vector<pair<int, int> > ans;

void dfs(int u, int par) {
    d[u] = low[u] = TIME++;
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        if (d[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (d[u] < low[v]) {
                if (u < v)
                    ans.emplace_back(u, v);
                else
                    ans.emplace_back(v, u);
            }
        } else {
            low[u] = min(low[u], d[v]);
        }
    }
}

void solve() {
    int n;
    while (cin >> n) {
        adj.assign(n, vector<int>());
        fori(i, 0, n) {
            int a, m;
            char c;
            cin >> a;
            cin >> c >> m >> c;
            fori(j, 0, m) {
                int b;
                cin >> b;
                adj[a].push_back(b);
            }
        }
        TIME = 1;
        d.assign(n, 0);
        low.assign(n, 0);
        ans.clear();
        fori(u, 0, n)
            if (d[u] == 0)
                dfs(u, -1);
        int k = ans.size();
        cout << k << " critical links" << ln;
        sort(all(ans));
        for (const auto &ee: ans)
            cout << ee.first << " - " << ee.second << ln;
        cout << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
