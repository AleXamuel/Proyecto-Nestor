//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3785
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"


int n, tiempo;
vector<vector<int> > adj;
vector<int> d, low, pi, Size;

int Find(int u) {
    int aux = u;
    while (u != pi[u])
        u = pi[u];
    while (aux != pi[aux]) {
        aux = pi[aux];
        pi[aux] = u;
    }
    return u;
}

void Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y)
        return;
    if (Size[x] < Size[y]) {
        pi[x] = y;
        Size[y] += Size[x];
    } else {
        pi[y] = x;
        Size[x] += Size[y];
    }
}


void dfs(int u, int par) {
    d[u] = low[u] = tiempo++;
    for (const auto &v: adj[u]) {
        if (v == par)
            continue;
        if (d[v] > 0)
            low[u] = min(low[u], d[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > d[u])
                Union(v, u);
        }
    }
}


void solve() {
    while (true) {
        int m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0)break;
        adj.assign(n, vector<int>());
        fori(i, 0, m) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        d.assign(n, 0);
        low.assign(n, 0);
        pi.assign(n, 0);
        Size.assign(n, 1);
        tiempo = 1;
        fori(i, 0, n)
            pi[i] = i;
        dfs(0, -1);
        fori(i, 0, q) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << (Find(a) == Find(b) ? "Y" : "N") << ln;
        }
        cout << "-" << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
