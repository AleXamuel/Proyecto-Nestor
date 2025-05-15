//https://cses.fi/problemset/task/1202/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 100001;
const int MOD = 1e9 + 7;
int n, m;
vector<pair<int,ll> > adj[MAXN];
bool visited[MAXN];
ll d[MAXN];
int cnt[MAXN];
int maxi[MAXN];
int mini[MAXN];


void dijkstra() {
    set<pair<ll, int> > Q;
    fill(visited, visited + n, false);
    fill(d, d + n,LLONG_MAX);
    fill(cnt, cnt + n, 0);
    fill(mini, mini + n, 0);
    fill(maxi, maxi + n, 0);
    d[0] = 0;
    Q.insert({d[0], 0});
    cnt[0] = 1;
    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        if (visited[u])
            continue;
        visited[u] = true;
        for (const auto &e: adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (!visited[v]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    cnt[v] = cnt[u];
                    mini[v] = mini[u] + 1;
                    maxi[v] = maxi[u] + 1;
                    Q.insert({d[v], v});
                } else if (d[u] + w == d[v]) {
                    cnt[v] = (cnt[v] % MOD + cnt[u] % MOD) % MOD;
                    mini[v] = min(mini[v], mini[u] + 1);
                    maxi[v] = max(maxi[v], maxi[u] + 1);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].emplace_back(b, w);
    }
    dijkstra();
    cout << d[n - 1] << " " << cnt[n - 1] << " " << mini[n - 1] << " " << maxi[n - 1] << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
