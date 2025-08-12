//https://codeforces.com/contest/2131/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"


const int MAX = 2e5;

vector<int> adj[MAX];
int deg[MAX];


void solve() {
    int n;
    cin >> n;
    For(i, 0, n) {
        adj[i].clear();
        deg[i] = 0;
    }
    For(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    if (n <= 3) {
        cout << 0 << ln;
        return;
    }
    int cnt = count(deg, deg + n, 1);
    int ans = cnt - 1;
    For(u, 0, n) {
        if (deg[u] == 1)
            ans = min(ans, cnt - 1);
        else {
            int cur = 0;
            for (const auto &v: adj[u])
                if (deg[v] == 1)
                    cur++;
            ans = min(ans, cnt - cur);
        }
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
