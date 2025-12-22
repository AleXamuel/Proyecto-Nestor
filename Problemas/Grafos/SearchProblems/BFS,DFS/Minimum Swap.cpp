//https://atcoder.jp/contests/abc436/tasks/abc436_e
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


const int MAX = 3e5;

vector<int> adj[MAX];
bool visited[MAX];


ll bfs(int s) {
    ll ans = 1;
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (const auto &v: adj[u])
            if (!visited[v]) {
                ans++;
                visited[v] = true;
                Q.push(v);
            }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    For(i, 0, n)
        adj[i].push_back(A[i] - 1);
    ll ans = 0;
    For(i, 0, n) {
        if (!visited[i]) {
            ll val = bfs(i);
            ans += val * (val - 1) / 2;
        }
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //  cin >> t;
    while (t--)
        solve();
}
