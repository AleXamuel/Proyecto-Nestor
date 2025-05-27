//https://www.spoj.com/problems/DISQUERY/
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
vector<int>parent,depth,weigth;
vector<vector<int>>up,table,table2;
void preprocess(int root) {
    l=ceil(log2(n));
    up.assign(n,vector<int>(l+1,root));
    table.assign(n,vector<int>(l+1,0));
    table2.assign(n,vector<int>(l+1,1e9));
    for(int i=0;i<n;i++) {
        up[i][0]=parent[i];
        table[i][0]=weigth[i];
        table2[i][0]=weigth[i];
    }

    for(int j=1;j<=l;j++)
        for(int i=0;i<n;i++)
            if(up[i][j-1]>=0) {
                up[i][j]=up[up[i][j-1]][j-1];
                table[i][j]=max(table[i][j-1],table[up[i][j-1]][j-1]);
                table2[i][j]=min(table2[i][j-1],table2[up[i][j-1]][j-1]);
            }


}
int binaryLifting(int u, int x) {
    for(int i=0;i<=l;i++)
        if(x&(1<<i))
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
int help(int u, int x) {
    int ans=0;
    for(int i=0;i<=l;i++)
        if(x&1<<i) {
            ans=max(ans,table[u][i]);
            u=up[u][i];
        }
    return ans;
}
int help2(int u, int x) {
    int ans=1e9;
    for(int i=0;i<=l;i++)
        if(x&1<<i) {
            ans=min(ans,table2[u][i]);
            u=up[u][i];
        }
    return ans;
}
int getMax(int a, int b) {
    int l=lca(a,b);
    return max(help(a,depth[a]-depth[l]),help(b,depth[b]-depth[l]));
}
int getMin(int a, int b) {
    int l=lca(a,b);
    return min(help2(a,depth[a]-depth[l]),help2(b,depth[b]-depth[l]));
}
void calc_depth(int u,int pi, int h,vector<vector<Pair>>&adj) {
    depth[u]=h;
    for(Pair p:adj[u]) {
        int v=p.first,w=p.second;
        if(v==pi)continue;
        parent[v]=u;
        weigth[v]=w;
        calc_depth(v,u,h+1,adj);
    }
}
void solve() {
    parent.assign(n,-1);
    depth.assign(n,0);
    weigth.assign(n,0);
    vector<int>in_deg(n,0);
    vector<vector<Pair>>adj(n,vector<Pair>());
    For(i,1,n) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        in_deg[v]++;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    calc_depth(0,-1,0,adj);
    preprocess(0);
    int q;cin>>q;
    while(q--) {
        int a,b;cin>>a>>b;
        a--,b--;
        cout<<getMin(a,b)<<" "<<getMax(a,b)<<ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    solve();
    return 0;
}
