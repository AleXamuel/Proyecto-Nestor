//https://codeforces.com/gym/105505/problem/g
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define dll long double
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
#define Vvi vector<vector<int>>
#define sz(A) (int)A.size()
#define Vi vector<ll>
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define RAYA cerr<<"=================================="<<endl
const int MAX = 1e5 + 2, MOD = 10007, MOD2 = 1202773163, INF = 1e9, base = 29;

struct edge {
    int v, w;
};

vector<edge> adj[MAX],Q[MAX];
int A[MAX], B[MAX], C[MAX],ans[MAX];


void dfs1(int u, int par) {
    vector<Pair > s;
    for (auto &[v,w]: adj[u]) {
        if (v == par)
            continue;
        dfs1(v,u);
        s.pb({B[v] + w, C[v]});
    }
    sort(all(s));
    if (!s.empty()) {
        if (adj[u].size() == 1)
            return;
        B[u] = s[0].first;
        A[s[0].second]++;
        C[u] = s[0].second;
    }
}
void change(int u, int v, int val) {
    if(C[u]==C[v]) {
        A[C[u]]--;
        vector<Pair > s;
        for(auto[node,w]:adj[u]) {
            if(node==v)continue;
            s.pb({B[node] + w, C[node]});
        }
        sort(all(s));
        B[u] = s[0].first;
        A[s[0].second]++;
        C[u] = s[0].second;
    }else {
        if(B[u]+val<B[v]||(B[u]+val==B[v]&&C[u]<C[v])) {
            A[C[v]]--;
            B[v]=B[u]+val;
            C[v]=C[u];
            A[C[u]]++;
        }
    }
}
void dfs(int u, int par) {
    for(auto[node,idx]:Q[u])
        ans[idx]=A[node];
    for (auto &[v,w]: adj[u]) {
        if (v == par)
            continue;
        change(u,v,w);
        dfs(v,u);
        change(v,u,w);
    }

}
void solve() {
    int n;
    cin >> n;
    For(I, 0, n+1) {
        adj[I].clear();
        Q[I].clear();
        A[I] = 0;
        B[I] = 0;

    }
    For(I, 0, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    For(i, 1, n+1) {
        if (adj[i].size() == 1) {
            A[i]++;
            C[i] = i;
        }
    }
    int q;cin>>q;
    For(i,0,q) {
        int u,v;cin>>u>>v;
        Q[v].pb({u,i});
    }
    dfs1(1, 0);
    dfs(1,0);
    For(i,0,q)
        cout<<ans[i]<<ln;
}

signed main() {
    //freopen("feast.in", "r",stdin);
    //freopen("feast.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
