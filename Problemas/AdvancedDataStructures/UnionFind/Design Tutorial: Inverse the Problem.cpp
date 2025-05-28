//https://codeforces.com/problemset/problem/472/D
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
#define Triple tuple<int,int,int>
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MOD = 1000000007;
const ll inf = -2e18;
//solution
vector<int>pi, Size;

int Find(int u) {
    int aux = u;
    while (u != pi[u])
        u = pi[u];
    while (aux != pi[aux]) {
        aux = pi[aux];
        pi[aux] = u;
    }
    return u;
}
void Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y)
        return;
    if (Size[x] < Size[y]) {
        pi[x] = y;
        Size[y] += Size[x];
    } else {
        pi[y] = x;
        Size[x] += Size[y];
    }
}
void bfs(int s, bool& flag, vector<vector<Pair>>& adj,vector<vector<int>>& grid) {
    queue<Pair> q;
    vector<bool>state(adj.size(),false);
    state[s]=true;
    q.emplace(s,0);
    while(!q.empty()) {
        Pair p=q.front();q.pop();
        int u=p.first,c=p.second;
        if(u!=s&&c==0||c!=grid[s][u])flag=false;
        for(Pair pp:adj[u]) {
            int v=pp.first,w=pp.second;
            if(!state[v]) {
                state[v]=true;
                q.emplace(v,c+w);
            }
        }
    }
}
void solve() {
    int n;
    cin>>n;
    Size.assign(n,1);
    pi.resize(n);
    For(i,0,n)
        pi[i]=i;
    vector<vector<int>> grid(n,vector<int>(n));
    For(i,0,n)
        For(j,0,n)
            cin>>grid[i][j];
    vector<Triple> edges;
    bool flag=true;
    For(i,0,n)
        For(j,i,n) {
            edges.eb(grid[i][j],i,j);
            if(grid[i][j]!=grid[j][i])
                flag=false;
        }
    sort(all(edges));
    vector<vector<Pair>> adj(n,vector<Pair>());
    for(auto&[w,u,v]:edges) {
        if(u==v&&w>0){flag=false;continue;}
        if(Find(u)!=Find(v)) {
            Union(u,v);
            adj[u].eb(v,w);
            adj[v].eb(u,w);
        }
    }
    For(i,0,n)
        bfs(i,flag,adj,grid);
    cout<<(flag?"YES":"NO")<<ln;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti=1;
    while (ti--)
        solve();
    return 0;
}
