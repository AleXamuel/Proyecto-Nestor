
typedef unsigned long long ll;
typedef pair<ll, int> Pair;
ll INF=18446744073709551615;
vector<ll> dijkstra(int source) {
    int n = adj.size();
    vector<ll> d(n, INF);
    d[source] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<bool> state(n, false);
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (state[u]) continue;
        state[u] = true;
        for (const Pair& edge : adj[u]) {
            ll w = edge.first;
            int v = edge.second;
            if(!state[v]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
    }
    return d;
}
