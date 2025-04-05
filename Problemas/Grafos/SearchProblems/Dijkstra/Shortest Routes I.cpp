//https://vjudge.net/problem/CSES-1671
#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
#include <queue>
#include <vector>
#define pb push_back
using namespace std;
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<Pair>> adj(n);

    for (int i = 0; i < m; i++) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u-=1;
        v-=1;
        adj[u].push_back({v, w});
    }
    vector<ll> a(n,INF);
    vector<ll> d=dijkstra(0,adj,a);
    cout<<0;
    for(int i=1;i<n;i++)
        cout<<" "<<d[i];

    return 0;
}
