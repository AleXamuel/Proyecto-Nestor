//https://www.spoj.com/problems/GOODA/
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<ll,int>
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const int INF = 1e9;
const int MAX = 1005;
vector<bool> visited;
 
void dfs(int v, vector<vector<int> > const &adj, vector<int> &output) {
    visited[v] = true;
    for (auto u: adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}
 
void kosaraju(vector<vector<int> > const &adj, vector<vector<int> > &components,
              vector<vector<int> > &adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();
    vector<int> order;
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);
    vector<vector<int> > adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u: adj[v])
            adj_rev[u].push_back(v);
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    vector<int> roots(n, 0);
    for (auto v: order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(begin(component), end(component));
            for (auto u: component)
                roots[u] = root;
        }
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u: adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}
ll dijkstra(int s, int t,vector<vector<int>>&adj,vector<ll>& a) {
    set<Pair,greater<Pair>> q;
    vector<ll> d(a.size(),0);
    vector<bool> state(a.size(),false);
    d[s]=a[s];
    q.insert({s,s});
    while (!q.empty()) {
        int u = (*q.begin()).second;
        q.erase(q.begin());
        if (state[u]) continue;
        state[u] = true;
        for (const int& v : adj[u]) {
            if(!state[v]) {
                ll w=a[v];
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    q.insert({d[v], v});
                }
            }
        }
    }
    return -d[t];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int> > adj(n, vector<int>());
    vector<int> a(n);
    vector<vector<int> > scc;
    vector<vector<int> > adj_cond;
    For(i, 0, n)
        cin >> a[i];
    s--;t--;
    For(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
    }
    kosaraju(adj, scc, adj_cond);
    vector<ll> pref(scc.size(), 0);
    unordered_map<int, int> mp;
    For(i, 0, scc.size()) {
        For(j, 0, scc[i].size()) {
            mp[scc[i][j]] = i;
            pref[i] += a[scc[i][j]];
        }
    }
    For(i,0,pref.size())
        pref[i]=-pref[i];
    vector<vector<int> > adj_rev(scc.size(), vector<int>());
    For(i, 0, adj_cond.size()) {
        if(adj_cond[i].empty())continue;
        for(int v:adj_cond[i])
            adj_rev[mp[i]].pb(mp[v]);
    }
    cout<<dijkstra(mp[s],mp[t],adj_rev,pref)<<ln;
    return 0;
}
 
//freopen("socdist.in", "r",stdin);
//fr    eopen("socdist.out", "w", stdout)
 
