//https://vjudge.net/problem/URAL-1471
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
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MOD = 1000000007;
const ll inf = -2e18;
//solution
int n, l;
vector<int>parent,depth,d;
vector<vector<int>>up;
vector<vector<Pair>>adj;
void preprocess(int root) {
    l=ceil(log2(n));
    up.assign(n,vector<int>(l+1,root));
    for(int i=0;i<n;i++)
        up[i][0]=parent[i];

    for(int j=1;j<=l;j++)
        for(int i=0;i<n;i++)
            if(up[i][j-1]>=0)
                up[i][j]=up[up[i][j-1]][j-1];


}
int binaryLifting(int u, int x) {
    for(int i=0;i<=l;i++)
        if(x&1<<i)
            u=up[u][i];
    return u;
}
int lca(int a, int b) {
    if(depth[a]<depth[b])
        swap(a,b);
    a=binaryLifting(a,depth[a]-depth[b]);
    if(a==b)return a;
    for(int i=l;i>=0;i--) {
        if(up[a][i]==up[b][i])
            continue;
        a=up[a][i];
        b=up[b][i];
    }
    return up[a][0];
}
void calc_depth(int u, int pi, int h,vector<vector<Pair>>&adj) {
    depth[u]=h;
    for(Pair p:adj[u]) {
        int v=p.first,w=p.second;
        if(v==pi)continue;
        parent[v]=u;
        d[v]=d[u]+w;
        calc_depth(v,u,h+1,adj);
    }
}

void solve() {
    cin>>n;
    parent.assign(n,-1);
    depth.assign(n,0);
    d.assign(n,0);
    adj.assign(n,vector<Pair>());
    For(i,1,n) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    d[0]=0;
    calc_depth(0,-1,0,adj);
    preprocess(0);
    int q;cin>>q;
    while(q--) {
        int u,v;cin>>u>>v;
        int l=lca(u,v);
        cout<<(d[u]+d[v]-2*d[l])<<ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti=1;
    while (ti--)
        solve();
    return 0;
}
