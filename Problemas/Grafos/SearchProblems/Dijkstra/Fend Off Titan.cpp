//https://open.kattis.com/problems/fendofftitan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
#define Pair pair<int,int>

struct Edge {
    ll w;
    int cntSha, cntTit;
};

const int MAX = 101;
int n;

Edge d[MAX];
bool visited[MAX];
vector<pair<int, pair<ll, int> > > adj[MAX];
using Item = pair<int, pair<int, pair<ll, int> > >;


void check(int curT, int curS, set<Item> &Q, int i, int j, int u, int v, ll w) {
    curT += i;
    curS += j;
    if (curT <= d[v].cntTit) {
        if (curT < d[v].cntTit) {
            d[v].cntTit = curT;
            d[v].cntSha = curS;
            d[v].w = d[u].w + w;
            Q.insert({curT, {curS, {d[u].w + w, v}}});
        } else if (curS < d[v].cntSha) {
            d[v].cntSha = curS;
            d[v].w = d[u].w + w;
            Q.insert({curT, {curS, {d[u].w + w, v}}});
        } else if (curS == d[v].cntSha && d[u].w + w < d[v].w) {
            d[v].w = d[u].w + w;
            Q.insert({curT, {curS, {d[u].w + w, v}}});
        }
    }
}

void dijkstra(int s) {
    set<Item> Q;
    Edge inf = {LLONG_MAX, INT_MAX,INT_MAX};
    fill(d, d + n, inf);
    fill(visited, visited + n, false);
    d[s] = {0, 0, 0};
    Q.insert({0, {0, {0, s}}});
    while (!Q.empty()) {
        auto e = Q.begin();
        int curT = e->first;
        int curS = e->second.first;
        int u = e->second.second.second;
        Q.erase(e);
        if (visited[u])
            continue;
        visited[u] = true;
        for (const auto &ee: adj[u]) {
            int v = ee.first;
            ll w = ee.second.first;
            int cond = ee.second.second;
            if (!visited[v]) {
                if (cond == 2)
                    check(curT, curS, Q, 1, 0, u, v, w);
                else if (cond == 1)
                    check(curT, curS, Q, 0, 1, u, v, w);
                else
                    check(curT, curS, Q, 0, 0, u, v, w);
            }
        }
    }
}

void solve() {
    int m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    For(i, 0, m) {
        int a, b, c;
        ll w;
        cin >> a >> b >> w >> c;
        a--;
        b--;
        adj[a].push_back({b, {w, c}});
        adj[b].push_back({a, {w, c}});
    }
    dijkstra(s);
    if (!visited[t])
        cout << "IMPOSSIBLE" << ln;
    else
        cout << d[t].w << " " << d[t].cntSha << " " << d[t].cntTit << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
