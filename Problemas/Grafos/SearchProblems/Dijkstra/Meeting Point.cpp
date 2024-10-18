//https://codeforces.com/gym/104736/problem/M
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef unsigned int uint;
typedef pair<uint, uint> Pair;

void dijkstra2(int source, vector<vector<Pair>>& graph, vector<uint>& d,int skip) {
    int n = graph.size();
    d.assign(n, numeric_limits<uint>::max());
    d[source] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<bool> state(n, false);
    pq.push({0, source});
    while (!pq.empty()) {
        uint u = pq.top().second;
        pq.pop();
        if(u==skip)
            continue;
        if (state[u]) continue;
        state[u] = true;
        for (const Pair& edge : graph[u]) {
            uint v = edge.first;
            uint w = edge.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}
void dijkstra(int source, vector<vector<Pair>>& graph, vector<uint>& d) {
    int n = graph.size();
    d.assign(n, numeric_limits<uint>::max());
    d[source] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<bool> state(n, false);
    pq.push({0, source});

    while (!pq.empty()) {
        uint u = pq.top().second;
        pq.pop();

        if (state[u]) continue;

        state[u] = true;

        for (const Pair& edge : graph[u]) {
            uint v = edge.first;
            uint w = edge.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p, g;
    cin >> n >> m;
    cin >> p >> g;
    vector<vector<Pair>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<uint> dist(n);
    vector<uint> dist2(n);
    p--;
    dijkstra(p, graph, dist);
    dijkstra2(p, graph, dist2,g-1);

    uint num = dist[g - 1] * 2;
    bool as = false;

    for (int i = 0; i < n; i++) {
        if (dist[i] == num && dist2[i] > num) {
            cout << i + 1 << " ";
            as = true;
        }
    }
    if (!as) {
        cout << "*" << endl;
    }

    return 0;
}
