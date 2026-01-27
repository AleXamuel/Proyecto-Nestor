//https://atcoder.jp/contests/arc084/tasks/arc084_b
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

bool visited[MAX];
int d[MAX];

void solve() {
    memset(visited, false, sizeof(visited));
    int n;
    cin >> n;
    fill(d, d + n + 1, 1 << 30);
    deque<int> Q;
    Q.push_front(1);
    d[1] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        if (visited[u])
            continue;
        int v1 = ((u % n) + 1) % n;
        int v2 = ((u % n) * (10 % n)) % n;
        if (!visited[v1] && d[u] + 1 < d[v1]) {
            Q.push_back(v1);
            d[v1] = d[u] + 1;
        }
        if (!visited[v2] && d[u] < d[v2]) {
            Q.push_front(v2);
            d[v2] = d[u];
        }
        visited[u] = true;
    }
    cout << d[0] + 1 << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
