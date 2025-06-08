//https://www.spoj.com/problems/CLFLARR/
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<ll,ll>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MOD = 1000000007;
const ll inf = -4e18;
//solution
vector<int> pi, Size, xp;

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
struct Query {
    int l,r,c;
};
void solve() {
    int n, q;
    cin >> n >> q;
    pi.resize(n+1);
    Size.resize(n+1);
    For(i, 0, n+1) {
        pi[i] = i;
        Size[i] = 1;
    }
    vector<Query>query(q);
    vector<int>answer(n);
    For(i,0,q)
        cin>>query[i].l>>query[i].r>>query[i].c;
    for (int i = q-1; i >= 0; i--) {
        int l = query[i].l-1;
        int r = query[i].r-1;
        int c = query[i].c;
        for (int v = Find(l); v <= r; v = Find(v)) {
            answer[v] = c;
            pi[v] = v + 1;
        }
    }
    for(int i:answer)
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
