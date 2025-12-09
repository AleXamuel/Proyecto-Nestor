//https://atcoder.jp/contests/abc435/tasks/abc435_d
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

const int MAX = 3e5;

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    for (const auto &v: adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1)
            dfs(v);
        else
            cout << (visited[v] ? "Yes" : "No") << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
