//https://codeforces.com/contest/2192/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)(v).size()
#define Pair pair<ll,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl


const int MAX = 2e5;

vector<int> adj[MAX];

int A[MAX], Md[MAX], d[MAX];
ll ans1[MAX], ans2[MAX], sum[MAX];


void dfs(int u, int par, int h) {
    sum[u] += A[u];
    Md[u] = d[u] = h;
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        dfs(v, u, h + 1);
        sum[u] += sum[v];
        ans1[u] += ans1[v] + sum[v];
        Md[u] = max(Md[u], Md[v]);
    }
}

void dfs(int u, int par) {
    vector<int> cur;
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        cur.push_back(Md[v]);
    }
    sort(all(cur));
    ll f = 0;
    ll s = 0;
    if (!cur.empty()) {
        f = cur.back();
        cur.pop_back();
    }
    if (!cur.empty())
        s = cur.back();

    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        dfs(v, u);
        if (Md[v] == f)
            ans2[u] = max({ans2[u], ans2[v], sum[v] * (s - d[v] + 1)});
        else
            ans2[u] = max({ans2[u], ans2[v], sum[v] * (f - d[v] + 1)});
    }
}

void solve() {
    int n;
    cin >> n;
    For(i, 0, n) {
        adj[i].clear();
        cin >> A[i];
        ans1[i] = ans2[i] = sum[i] = d[i] = Md[i] = 0;
    }

    For(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    dfs(0, -1);
    For(i, 0, n)
        cout << ans1[i] + ans2[i] << " ";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
