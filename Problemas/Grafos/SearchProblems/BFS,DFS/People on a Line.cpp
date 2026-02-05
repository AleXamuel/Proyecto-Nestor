//https://atcoder.jp/contests/abc087/tasks/arc090_b
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
#define Pair pair<int,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


const int MAX = 1e5;

vector<Pair > adj[MAX];
bool visited[MAX];
ll A[MAX];

bool dfs(int u, ll val) {
    bool cond = true;
    visited[u] = true;
    A[u] = val;
    for (const auto &e: adj[u]) {
        int v = e.first;
        ll d = e.second;
        if (!visited[v])
            cond &= dfs(v, val + d);
        else
            cond &= (A[u] + d == A[v]);
    }
    return cond;
}

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        ll d;
        cin >> a >> b >> d;
        a--;
        b--;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, -d);
    }
    For(u, 0, n)
        if (!visited[u]) {
            if (!dfs(u, 0)) {
                cout << "No" << ln;
                return;
            }
        }
    cout << "Yes" << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
