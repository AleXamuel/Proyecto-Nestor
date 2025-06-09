//https://codeforces.com/contest/2117/problem/F
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

const int MAX = 2e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> adj[MAX];
int n;

int childCnt[MAX];
int d[MAX];


ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}


void dfs(int u, int par) {
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        childCnt[u]++;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

void solve() {
    cin >> n;
    For(i, 0, n)
        adj[i].clear();
    For(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(childCnt, childCnt + n, 0);
    fill(d, d + n, 0);
    d[0] = 1;
    dfs(0, -1);
    vector<int> leafs;
    int lca = -1;
    For(i, 0, n) {
        if (childCnt[i] == 0)
            leafs.push_back(i);
        else if (childCnt[i] == 2 && lca == -1)
            lca = i;
        else if (childCnt[i] == 2) {
            cout << 0 << ln;
            return;
        }
    }
    if (leafs.size() > 2) {
        cout << 0 << ln;
        return;
    }
    ll x = n;
    if (leafs.size() == 1) {
        cout << mod_pow(2, x, MOD) << ln;
    } else {
        ll ans = mod_pow(2, d[lca], MOD);
        int l1 = leafs.front();
        int l2 = leafs.back();
        ll cntleft = d[l1] - d[lca];
        ll cntright = d[l2] - d[lca];
        ll a = mod_pow(2, abs(cntleft - cntright), MOD);
        ll b = mod_pow(2, max(abs(cntleft - cntright) - 1, 0ll), MOD);
        ll k = (a + b) % MOD;
        cout << ans % MOD * (k % MOD) % MOD << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
