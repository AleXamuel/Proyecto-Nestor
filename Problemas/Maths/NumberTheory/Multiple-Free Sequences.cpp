//https://atcoder.jp/contests/abc446/tasks/abc446_e
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

const int MAX = 1e3 + 1;

vector<Pair > adj[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int i, int j) {
    visited[i][j] = true;
    for (const auto [x,y]: adj[i][j]) {
        if (!visited[x][y])
            dfs(x, y);
    }
}


void solve() {
    int M, A, B;
    cin >> M >> A >> B;

    For(i, 0, M)
        For(j, 0, M) {
            adj[j][(A * j + B * i) % M].emplace_back(i, j);
            visited[i][j] = false;
        }

    For(i, 0, M) {
        if (!visited[i][0])
            dfs(i, 0);
        if (!visited[0][i])
            dfs(0, i);
    }
    int ans = 0;
    For(i, 0, M)
        For(j, 0, M)
            if (!visited[i][j])
                ans++;

    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}
