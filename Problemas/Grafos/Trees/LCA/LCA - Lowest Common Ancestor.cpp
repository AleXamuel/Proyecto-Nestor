//https://www.spoj.com/problems/LCA/
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
vector<int>parent,depth;
vector<vector<int>>up;
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
int calc_depth(int u) {
    if(parent[u]==-1)return depth[u]=0;
    if(depth[u]>=0)return depth[u];
    return depth[u]=calc_depth(parent[u])+1;
}
void solve() {
    cin>>n;
    parent.assign(n,-1);
    depth.assign(n,-1);
    For(i,0,n) {
        int m;cin>>m;
        For(j,0,m) {
            int x;
            cin>>x;
            x--;
            parent[x]=i;
        }
    }
    int root=-1;
    For(i,0,n)
        if(parent[i]==-1) {
            root=i;
            break;
        }
    For(i,0,n)
        calc_depth(i);
    preprocess(root);

    int q;cin>>q;
    while(q--) {
        int a,b;cin>>a>>b;
        a--,b--;
        cout<<lca(a,b)+1<<ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti;
    cin >> ti;
    For(i,1,ti+1) {
        cout<<"Case "<<i<<":"<<ln;
        solve();
    }
    return 0;
}
