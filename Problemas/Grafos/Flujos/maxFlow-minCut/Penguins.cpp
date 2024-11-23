//https://vjudge.net/problem/LightOJ-1154
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
int rock[102][4];
double dis(int a, int b, int c, int d) {
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tim,tc=0;
    cin>>tim;
    while(tim--) {
        int m;
        cin>>m;
        double dist;
        cin>>dist;
        for(int i =0;i<m;i++)
            cin>>rock[i][0]>>rock[i][1]>>rock[i][2]>>rock[i][3];
        int n=2*m+1;
        int s=n-1;

        vector<int> l;
        for (int k =0;k<m;k++) {
            Dinic d(n);
            int c=0;
            for (int i =0;i<m;i++) {
                int a=rock[i][2];
                c+=a;
                if(a)
                    d.add_edge(s,i,a);
                d.add_edge(i,i+m,rock[i][3]);
                for (int j =i+1;j<m;j++) {
                    if(dis(rock[i][0],rock[i][1],rock[j][0],rock[j][1])<=dist) {
                        d.add_edge(i+m,j,10000000000);
                        d.add_edge(j+m,i,10000000000);

                    }
                }
            }
            if(d.flow(s,k)==c)
                l.push_back(k);
        }
        if(l.empty())
            cout<<"Case "<<++tc<<": -1"<<"\n";
        else {
            cout<<"Case "<<++tc<<":";
            for(auto i:l)
                cout<<" "<<i;
            cout<<"\n";
        }
    }
    return 0;
}
