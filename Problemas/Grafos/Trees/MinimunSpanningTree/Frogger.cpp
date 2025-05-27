//https://vjudge.net/problem/UVA-534
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 201;
int n;
int pi[MAXN];
int Size[MAXN];

unordered_map<int, pair<int, int> > h;
vector<pair<double, pair<int, int> > > edges;


double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2));
}

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
    int caso = 1;
    while (cin >> n && n != 0) {
        h.clear();
        edges.clear();
        For(i, 0, n) {
            int x, y;
            cin >> x >> y;
            h[i] = {x, y};
            pi[i] = i;
            Size[i] = 1;
        }
        For(i, 0, n)
            For(j, i+1, n) {
                double cur = dist(h[i], h[j]);
                edges.push_back({cur, {i, j}});
            }
        sort(all(edges));
        double ans = -1;
        int cnt = 0;
        for (const auto &e: edges) {
            double w = e.first;
            int u = e.second.first;
            int v = e.second.second;
            if (Find(0) == Find(1) || cnt >= n)
                break;
            if (Find(u) != Find(v)) {
                ans = max(ans, w);
                Union(u, v);
                cnt++;
            }
        }
        cout << "Scenario #" << caso++ << ln;
        cout.precision(3);
        cout << fixed;
        cout << "Frog Distance = " << ans << ln;
        cout << ln;
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
