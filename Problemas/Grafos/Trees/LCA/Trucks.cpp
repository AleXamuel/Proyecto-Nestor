//https://vjudge.net/problem/UVA-12655
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
//vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MOD = 1000000007;
const ll inf = -2e18;
//solution
int n, l;
vector<int> parent, depth,d;
vector<vector<int> > up,table;
vector<vector<Pair> > adj;

void preprocess(int root) {
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1, root));
    table.assign(n, vector<int>(l + 1, -1e9));
    for (int i = 0; i < n; i++) {
        up[i][0] = parent[i];
        table[i][0]=d[i];
    }

    for (int j = 1; j <= l; j++)
        for (int i = 0; i < n; i++)
            if (up[i][j - 1] >= 0) {
                up[i][j] = up[up[i][j - 1]][j - 1];
                table[i][j]=max(table[i][j-1],table[up[i][j-1]][j-1]);
            }
}

int binaryLifting(int u, int x) {
    for (int i = 0; i <= l; i++)
        if (x & (1 << i))
            u = up[u][i];
    return u;
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    a = binaryLifting(a, depth[a] - depth[b]);
    if (a == b)return a;
    for (int i = l; i >= 0; i--) {
        if (up[a][i] == up[b][i])
            continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}
int help(int u, int x) {
    int ans=-1e9;
    for (int i = 0; i <= l; i++)
        if (x & (1 << i)) {
            ans=max(ans,table[u][i]);
            u = up[u][i];
        }
    return ans;
}

int getAns(int a, int b) {
    int l=lca(a,b);
    return max(help(a,depth[a]-depth[l]),help(b,depth[b]-depth[l]));
}

int calc_depth(int u) {
    if(parent[u]==-1)return depth[u]=0;
    if(depth[u]>=0)return depth[u];
    return depth[u]=calc_depth(parent[u])+1;
}
void prim() {
    int n = adj.size();
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<bool> state(n, false);
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (state[u]) continue;
        state[u] = true;
        for (const Pair& edge : adj[u]) {
            ll w = edge.first;
            int v = edge.second;
            if(!state[v]) {
                if (w < d[v]) {
                    d[v] = w;
                    parent[v]=u;
                    pq.push({d[v], v});
                }
            }
        }
    }
}
void solve() {
    int m,q;
    cin>>m>>q;
    parent.assign(n, -1);
    depth.assign(n, -1);
    d.assign(n, 1e9);
    adj.assign(n,vector<Pair>());
    For(i,0,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].eb(-w,v);
        adj[v].eb(-w,u);
    }
    prim();
    For(i,0,n)
        calc_depth(i);
    preprocess(0);
    while(q--) {
        int u,v;cin>>u>>v;u--,v--;
        cout<<-getAns(u,v)<<ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti = 1;
    while (cin>>n) {
        solve();
    }
    return 0;
}
