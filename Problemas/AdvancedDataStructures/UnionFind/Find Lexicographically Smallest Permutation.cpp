//https://www.spoj.com/problems/IITKWPCI/
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
void solve() {
    int n, m;
    cin>>n>>m;
    vector<int>a(n);
    pi.resize(n);
    Size.resize(n);
    For(i, 0, n) {
        pi[i] = i;
        Size[i] = 1;
    }
    For(i,0,n)
        cin>>a[i];
    For(i,0,m) {
        int u,v;cin>>u>>v;
        u--,v--;
        Union(u,v);
    }
    vector<vector<int>>let(n,vector<int>());
    For(i,0,n)
        let[Find(i)].pb(a[i]);
    For(i,0,n)
        sort(all(let[i]),greater<int>());
    For(i,0,n) {
        int x=Find(i);
        cout<<let[x].back()<<" ";
        let[x].pop_back();
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti = 1;
    cin>>ti;
    while (ti--) {
        solve();
        cout<<ln;
    }
    return 0;
}
 
