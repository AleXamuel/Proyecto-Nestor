typedef unsigned long long ll;
typedef pair<ll, ll> Pair;
ll INF=18446744073709551615;
vector<ll> dijkstra(int source, vector<vector<Pair>>& graph, vector<ll>& d) {
    int n = graph.size();
    d.assign(n, numeric_limits<ll>::max());
    d[source] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<bool> state(n, false);
    pq.push({0, source});
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (state[u]) continue;
        state[u] = true;
        for (const Pair& edge : graph[u]) {
            ll v = edge.first;
            ll w = edge.second;
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
