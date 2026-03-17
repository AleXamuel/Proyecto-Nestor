//https://atcoder.jp/contests/abc120/tasks/abc120_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

const int MAX = 1e5;

int pi[MAX];
ll Size[MAX];

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
    ll n, m;
    cin >> n >> m;
    For(i, 0, n) {
        pi[i] = i;
        Size[i] = 1;
    }
    vector<Pair > edges(m);
    For(i, 0, m) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    vector<ll> ans(m + 1);
    ans[m] = (n * (n - 1)) / 2;
    Rfor(i, m-1, 0) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (Find(a) == Find(b))
            ans[i] = ans[i + 1];
        else {
            ans[i] = ans[i + 1] - (Size[Find(a)] * Size[Find(b)]);
            Union(a, b);
        }
    }
    For(i, 1, m+1)
        cout << ans[i] << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
