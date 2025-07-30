//https://codeforces.com/problemset/problem/237/E
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int nmax = 2e5 + 1, MOD = 998244353, INF = 1e9;

struct edge {
    int from, to, flow, cost;

    edge(int fr, int t, int fl, int c) {
        from = fr;
        to = t;
        flow = fl;
        cost = c;
    }
};

vector<edge> Edges;
vector<int> adj[nmax];
int d[nmax], pi[nmax];

void addEdge(int u, int v, int f, int c) {
    adj[u].push_back(Edges.size());
    Edges.push_back(edge(u, v, f, c));
    adj[v].push_back(Edges.size());
    Edges.push_back(edge(v, u, 0, -c));
}

void shortest_path(int n, int s) {
    bool state[nmax];
    for (int i = 0; i < n; i++)
        d[i] = INF, pi[i] = -1, state[i] = 0;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        state[u] = 0;
        for (int i = 0; i < adj[u].size(); i++) {
            int id = adj[u][i];
            int v = Edges[id].to;
            if (Edges[id].flow > 0 && d[v] > d[u] + Edges[id].cost) {
                pi[v] = id;
                d[v] = d[u] + Edges[id].cost;
                if (!state[v]) state[v] = 1, q.push(v);
            }
        }
    }
}

int min_cost_flow(int n, int k, int s, int t) {
    int flow = 0, ret = 0;
    while (flow < k) {
        shortest_path(n, s);
        if (d[t] == INF)return -1;
        int f = k - flow, cur = t;
        while (cur != s) {
            f = min(f, Edges[pi[cur]].flow);
            cur = Edges[pi[cur]].from;
        }
        flow += f;
        ret += f * d[t];
        cur = t;
        while (cur != s) {
            Edges[pi[cur]].flow -= f;
            Edges[pi[cur] ^ 1].flow += f;
            cur = Edges[pi[cur]].from;
        }
    }
    return flow < k ? -1 : ret;
}

void solve() {
    string s;
    int m;
    cin >> s >> m;
    int n=28+m;
    int sc=26+m,tc=27+m;
    For(i,0,m) {
        int x;
        string t;cin>>t>>x;
        addEdge(sc,i,x,0);
        unordered_map<char,int>mp;
        for(char c:t)
            mp[c]++;
        for(auto[a,b]:mp)
            addEdge(i,a-'a'+m,b,i+1);
    }
    unordered_map<char,int>mp;
    for(char c:s)
        mp[c]++;
    for(auto[a,b]:mp)
        addEdge(a-'a'+m,tc,b,0);

    cout<<min_cost_flow(n,s.size(),sc,tc);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
