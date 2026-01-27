//https://atcoder.jp/contests/abc077/tasks/arc084_b
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

const int MAX = 2e5 + 1;

bool visited[MAX];
ll d[MAX];

void solve() {
    memset(visited, false, sizeof(visited));
    ll n;
    cin >> n;
    fill(d, d + n + 1,INF(int));
    set<Pair > Q;
    Q.insert({0, 1});
    d[1] = 0;
    while (!Q.empty()) {
        auto e = Q.begin();
        ll u = e->second;
        if (u == 0) {
            cout << d[u] + 1 << ln;
            return;
        }
        Q.erase(e);
        if (visited[u])
            continue;
        ll v1 = ((u % n) + 1) % n;
        ll v2 = ((u % n) * (10 % n)) % n;
        if (!visited[v2] && d[u] < d[v2]) {
            Q.insert({d[u], v2});
            d[v2] = d[u];
        }
        if (!visited[v1] && d[u] + 1 < d[v1]) {
            Q.insert({d[u] + 1, v1});
            d[v1] = d[u] + 1;
        }
        visited[u] = true;
    }
    assert(false);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
