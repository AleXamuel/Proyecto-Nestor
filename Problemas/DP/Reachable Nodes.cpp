//https://cses.fi/problemset/task/2138
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
#define Pair pair<ll,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


const int MAX = 5e4;

vector<int> adj[MAX];
bitset<MAX> A[MAX];
bool visited[MAX];


void dfs(int u) {
    visited[u] = true;
    bitset<MAX> cur;
    cur[u] = true;
    for (const auto &v: adj[u]) {
        if (!visited[v])
            dfs(v);
        cur |= A[v];
    }
    A[u] = cur;
}

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    For(i, 0, n)
        if (!visited[i])
            dfs(i);
    For(i, 0, n)
        cout << A[i].count() << (i == n - 1 ? "" : " ");
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
