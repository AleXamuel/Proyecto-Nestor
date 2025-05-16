//https://vjudge.net/problem/UVA-10099
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 101;
int n;
vector<pair<int,ll> > adj[MAXN];
ll d[MAXN];
int pi[MAXN];
bool visited[MAXN];

void prim(int s) {
    set<pair<ll, int> > Q;
    d[s] = s;
    Q.insert({d[s], s});
    while (!Q.empty()) {
        int u = Q.rbegin()->second;
        Q.erase(*Q.rbegin());
        if (visited[u])
            continue;
        visited[u] = true;
        for (const auto &e: adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (!visited[v] && w > d[v]) {
                d[v] = w;
                pi[v] = u;
                Q.insert({d[v], v});
            }
        }
    }
}


void solve() {
    int m;
    int cnt = 1;
    while (cin >> n >> m && n != 0 && m != 0) {
        For(i, 0, n) {
            adj[i].clear();
            pi[i] = -1;
            d[i] = -1;
            visited[i] = false;
        }
        For(i, 0, m) {
            int a, b;
            ll w;
            cin >> a >> b >> w;
            a--;
            b--;
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }
        int s, t, p;
        cin >> s >> t >> p;
        s--;
        t--;
        prim(s);
        ll ans = LLONG_MAX;
        while (t != s) {
            ans = min(ans, d[t]);
            t = pi[t];
        }
        cout << "Scenario #" << cnt++ << ln;
        cout << "Minimum Number of Trips = ";
        cout << (p + ans - 2) / (ans - 1) << ln;
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
