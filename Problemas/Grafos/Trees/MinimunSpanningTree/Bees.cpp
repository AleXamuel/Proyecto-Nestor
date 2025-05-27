//https://codeforces.com/gym/100238/attachments
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 1e6;
int n, m, p1, p2;
int pi[MAXN];
int Size[MAXN];

int dir[1001][1001];
vector<pair<int, int> > edges[1000];


int dist(const int x1, const int y1, const int x2, const int y2) {
    return (x1 * x2 + p1 * y1 * y2) % p2;
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
    const int x = Find(u);
    const int y = Find(v);
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
    cin >> n >> m >> p1 >> p2;
    int c = 0;
    For(i, 1, n+1)
        For(j, 1, m+1) {
            dir[i][j] = c;
            pi[c] = c;
            Size[c] = 1;
            c++;
        }
    For(i, 1, n+1)
        For(j, 1, m+1) {
            int u = dir[i][j];
            if (i + 1 <= n) {
                const int w = dist(i, j, i + 1, j);
                int v = dir[i + 1][j];
                edges[w].emplace_back(u, v);
            }
            if (j + 1 <= m) {
                const int w = dist(i, j, i, j + 1);
                int v = dir[i][j + 1];
                edges[w].emplace_back(u, v);
            }
            if (i + 1 <= n && j + 1 <= m) {
                const int w = dist(i, j, i + 1, j + 1);
                int v = dir[i + 1][j + 1];
                edges[w].emplace_back(u, v);
            }
        }

    int cost = 0;
    int cnt = 0;
    for (int w = 0; w < 1000 && cnt < c; w++)
        for (const auto &e: edges[w]) {
            const int u = e.first;
            const int v = e.second;
            if (cnt >= c)
                break;
            if (Find(u) != Find(v)) {
                Union(u, v);
                cost += w;
                cnt++;
            }
        }
    cout << cost << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bees.in", "r", stdin);
    freopen("bees.out", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
