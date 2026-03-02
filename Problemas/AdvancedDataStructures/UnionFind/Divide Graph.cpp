//https://atcoder.jp/contests/abc447/tasks/abc447_e
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


const int MAX = 2e5 + 1;
const int MOD = 998244353;

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int pi[MAX];
int Size[MAX];

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
    cin >> n >> m;
    For(i, 0, n) {
        pi[i] = i;
        Size[i] = 1;
    }
    vector<Pair > edges;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a - 1, b - 1);
    }
    ll ans = 0;
    int N = n;
    Rfor(i, m-1, 0) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (Find(u) == Find(v))
            continue;
        if (N > 2) {
            Union(u, v);
            N--;
            continue;
        }
        ans += binpow(2, (ll) i + 1);
        ans %= MOD;
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
