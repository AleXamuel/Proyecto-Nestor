//https://vjudge.net/problem/LightOJ-1155
#include <bits/stdc++.h>
#define ll long long;
using namespace std;struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n) : n(n){
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow(int _s, int _t) {
        s=_s,t=_t;
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int regul[105];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tim,tc=0;
    cin>>tim;
    while(tim--) {
        int n;
        cin>>n;
        for (int i =0; i < n; i++)
            cin>>regul[i];
        int g=2*n+2;
        int s=g-2,t=g-1;
        Dinic d(g);
        for (int i =0; i < n; i++)
            d.add_edge(i,i+n,regul[i]);
        int m;
        cin>>m;
        for (int i =0; i < m; i++) {
            int u,v,c;
            cin>>u>>v>>c;
            u--,v--;
            d.add_edge(u+n,v,c);
        }
        int B,D;
        cin>>B>>D;
        for (int i =0; i < B; i++) {
            int v;
            cin>>v;
            v--;
            d.add_edge(s,v,1<<30);
        }
        for (int i =0; i < D; i++) {
            int u;
            cin>>u;
            u--;
            d.add_edge(u+n,t,1<<30);
        }
        cout<<"Case "<<++tc<<": "<<d.flow(s,t)<<"\n";
    }
    return 0;
}
