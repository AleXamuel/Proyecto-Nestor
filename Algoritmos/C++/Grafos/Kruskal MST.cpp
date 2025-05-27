using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 20001;
vector<pair<int, pair<int, int> > > edges;
int pi[MAXN];
int Size[MAXN];
int n;

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


void solve() {
    int m;
    cin >> n >> m;
    For(i, 0, n) {
        Size[i] = 1;
        pi[i] = i;
    }
    edges.clear();
    For(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(all(edges));
    int cost = n;
    for (const auto &ee: edges) {
        int w = ee.first;
        int u = ee.second.first;
        int v = ee.second.second;
        if (Find(u) != Find(v)) {
            cost += w;
            Union(u, v);
        }
    }
    cout << cost << ln;
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
