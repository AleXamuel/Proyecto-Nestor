//https://cses.fi/problemset/task/1686/
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<int> a(n);
    vector<vector<int> > scc;
    vector<vector<int> > adj_cond;
    For(i, 0, n)
        cin >> a[i];
    For(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
    }
    kosaraju(adj, scc, adj_cond);
    vector<ll> pref(scc.size(), 0);
    unordered_map<int,int>mp;
    For(i, 0, scc.size()) {
        For(j, 0, scc[i].size()) {
            mp[scc[i][j]]=i;
            pref[i] += a[scc[i][j]];
        }
    }
    vector<int> inDeg(adj_cond.size(), 0);
    For(i, 0, adj_cond.size())
        for (auto v: adj_cond[i])
            inDeg[v]++;
    queue<int> q;
    For(i, 0, inDeg.size())
        if (inDeg[i] == 0)
            q.push(i);
    vector<ll>dp(scc.size());
    For(i,0,scc.size())
        dp[i]=pref[i];
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: adj_cond[u]) {
            if(dp[mp[u]]+pref[mp[v]]>dp[mp[v]]) {
                dp[mp[v]] = dp[mp[u]]+pref[mp[v]];
                q.push(v);
            }
        }
    }
    ll ans=*max_element(dp.begin(), dp.end());
    cout << ans << endl;
    return 0;
}

//freopen("socdist.in", "r",stdin);
//fr    eopen("socdist.out", "w", stdout)
