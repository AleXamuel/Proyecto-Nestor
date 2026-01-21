//https://cses.fi/problemset/task/1706
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

const int MAX = 1e5 + 1;

vector<int> adj[MAX];
bool visited[MAX];

int bfs(int s) {
    visited[s] = true;
    queue<int> Q;
    Q.push(s);
    int cnt = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (const auto &v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                Q.push(v);
                cnt++;
            }
        }
    }
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> A;
    For(i, 1, n+1)
        if (!visited[i])
            A.push_back(bfs(i));
    bitset<MAX> ans;
    ans[0] = 1;
    for (const auto &i: A)
        ans |= ans << i;
    For(i, 1, n+1)
        cout << ans[i];
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
