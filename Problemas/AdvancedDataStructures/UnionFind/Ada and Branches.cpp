//https://www.spoj.com/problems/ADABRANC/
#include <bits/stdc++.h>
using namespace std;
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
const int MOD = 998244353;
const ll inf = -4e18;
//solution
vector<int> pi, Size;

int Find(int u) {
    if (pi[u] == u)return u;
    return pi[u] = Find(pi[u]);
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

struct edge {
    int u, v, w;
    bool operator<(const edge &o) const {
        return w > o.w;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    pi.resize(n);
    Size.resize(n);
    For(i, 0, n) {
        pi[i] = i;
        Size[i] = 1;
    }
    vector<edge> Edge(m),que(q);
    For(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge[i] = {u, v, w};
    }
    vector<int>ans(q);
    For(i,0,q) {
        int v,w;cin>>v>>w;
        que[i]={i,v,w};
    }
    sort(all(Edge));
    sort(all(que));
    int idx=0;
    for(edge e:que) {
        int s=e.v,y=e.w,i=e.u;
        while(idx<m&&Edge[idx].w>=y) {
            Union(Edge[idx].u,Edge[idx].v);
            idx++;
        }
        int f=Find(s);
        ans[i]=Size[f];
    }
    for(int i:ans)
        cout<<i<<ln;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti = 1;
    while (ti--) {
        solve();
    }
    return 0;
}
