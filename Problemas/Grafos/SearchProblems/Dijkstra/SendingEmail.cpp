//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1927
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

const int INF = 1000000000; 
vector<vector<pair<int, int>>> adj;
int n;

void dijkstra(int s, vector<int>& d, vector<int>& pi) {
    d.assign(n, INF);
    pi.assign(n, -1);
    d[s] = 0;
    set<pair<int, int>> Q;
    Q.insert({0, s});
    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());
        for (pair<int,int> ee : adj[u]) {
            int v = ee.first;
            int w = ee.second;
            if (d[u] + w < d[v]) {
                Q.erase({d[v], v});
                d[v] = d[u] + w;
                pi[v] = u;
                Q.insert({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int m;
        cin >> m;
        int s, t;
        cin >> s >> t;
        adj.assign(n, vector<pair<int, int>>());
        for (int j = 0; j < m; j++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        vector<int> d, pi;
        dijkstra(s, d, pi);
        int ans = d[t];
        cout << "Case #" << (i + 1) << ": " << (ans == INF ? "unreachable" : to_string(ans)) << "\n";
    }
    return 0;
}
