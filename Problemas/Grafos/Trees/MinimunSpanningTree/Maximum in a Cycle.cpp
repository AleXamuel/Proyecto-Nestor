//https://codeforces.com/gym/100238/attachments
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 1e5 + 2;

vector<pair<int, int> > edges[MAXN];
int pi[MAXN];
int Size[MAXN];

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
    int n, m;
    cin >> n >> m;
    For(i, 0, n) {
        pi[i] = i;
        Size[i] = 1;
    }
    For(i, 1, m+1) {
        int a, b;
        cin >> a >> b;
        edges[i].emplace_back(a - 1, b - 1);
    }

    int cnt = 0;
    vector<int> ans;
    for (int w = 1; w < MAXN && cnt < n; w++)
        for (const auto &e: edges[w]) {
            int u = e.first;
            int v = e.second;
            if (Find(u) != Find(v)) {
                Union(u, v);
                ans.push_back(w);
                cnt++;
            }
        }
    cout << ans.size() << ln;
    for (const auto &i: ans)
        cout << i << " ";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("maxincycle.in", "r", stdin);
    freopen("maxincycle.out", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
