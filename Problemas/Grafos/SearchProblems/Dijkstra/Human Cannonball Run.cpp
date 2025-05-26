//https://open.kattis.com/problems/humancannonball
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

unordered_map<int, pair<double, double> > h;
const int MAXN = 102;
vector<pair<int, double> > adj[MAXN];
double d[MAXN];
bool visited[MAXN];


double dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2));
}

void dijkstra() {
    set<pair<double, int> > Q;
    d[0] = 0;
    Q.insert({d[0], 0});
    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        if (visited[u])
            continue;
        visited[u] = true;
        for (const auto &e: adj[u]) {
            int v = e.first;
            double w = e.second;
            if (!visited[v] && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                Q.insert({d[v], v});
            }
        }
    }
}


void solve() {
    double x, y;
    cin >> x >> y;
    h[0] = {x, y};
    cin >> x >> y;
    h[1] = {x, y};
    int n;
    cin >> n;
    n += 2;
    For(i, 2, n) {
        cin >> x >> y;
        h[i] = {x, y};
    }
    For(i, 1, n)
        adj[0].emplace_back(i, dist(h[0], h[i]) / 5);

    For(i, 2, n) {
        double cur = dist(h[i], h[1]);
        adj[i].emplace_back(1, min(abs(cur - 50) / 5 + 2, cur / 5));
        For(j, 2, n) {
            cur = dist(h[i], h[j]);
            adj[i].emplace_back(j, min(abs(cur - 50) / 5 + 2, cur / 5));
        }
    }
    fill(d, d + n, DBL_MAX);
    fill(visited, visited + n, false);
    dijkstra();
    cout.precision(4);
    cout << fixed;
    cout << d[1] << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
