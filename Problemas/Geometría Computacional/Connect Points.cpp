//https://codeforces.com/gym/100238/attachments
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

struct pt {
    int x, y;
};

const int MAXN = 201;
int n;
vector<pair<double, pair<int, int> > > edges;
pt h[MAXN];
int pi[MAXN];
int Size[MAXN];


double dist(pt a, pt b) {
    return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
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
    cin >> n;
    For(i, 0, n) {
        pt a;
        cin >> a.x >> a.y;
        h[i] = a;
        pi[i] = i;
        Size[i] = 1;
    }
    For(i, 0, n)
        For(j, i+1, n)
            edges.push_back({dist(h[i], h[j]), {i, j}});
    sort(all(edges));
    vector<pair<int, int> > ans;
    int cnt = 0;
    double cost = 0;
    for (const auto &e: edges) {
        double w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (cnt >= n)
            break;
        if (Find(u) != Find(v)) {
            Union(u, v);
            cnt++;
            cost += w;
            ans.emplace_back(u, v);
        }
    }
    cout.precision(8);
    cout << fixed;
    cout << cost << ln;
    cout << ans.size() << ln;
    for (const auto &e: ans)
        cout << e.first + 1 << " " << e.second + 1 << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
