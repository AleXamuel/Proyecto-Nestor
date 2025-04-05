//https://vjudge.net/problem/CSES-2432
#include <bits/stdc++.h>
using namespace std;
struct FlowEdge {
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

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
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

    long long flow() {
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
int index(int n, int m,int i, int j, int d){
    return d==0 ? i*m+j:i*m+j+n*m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m=(n<<1)+2;
    int s=m-2,t=m-1;
    Dinic fl(m,s,t);
    int row=0,col=0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        row+=a;
        if(a)
            fl.add_edge(s,i,a);
    }
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        col+=a;
        if(a)
            fl.add_edge(i+n,t,a);
    }
    if(col!=row) {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fl.add_edge(i,j+n,1);

    int ans=fl.flow();
    if(ans!=col) {
        cout<<"-1"<<endl;
        return 0;
    }
    vector<vector<bool>>state(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
        for(auto j:fl.adj[i]) {
            if(j&1)continue;
            if(fl.edges[j].flow)
                state[i][fl.edges[j].u-n] = true;
        }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<(state[i][j]?"X":".");
        cout<<"\n";
    }
    return 0;
}
