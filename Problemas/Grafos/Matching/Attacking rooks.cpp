//https://vjudge.net/problem/UVA-12668
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define ln "\n"
#define pb push_back

const int INF = 1e9;
vector<vector<int> > G;
vector<int> match, dist;
int n; 

bool bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        } else dist[i] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u != 0) {
            for (int v: G[u])
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
        }
    }
    return dist[0] != INF;
}

bool dfs(int u) {
    if (u == 0) return true;
    for (int v: G[u]) {
        if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

int hopcroft_karp() {
    int matching = 0;
    while (bfs())
        for (int i = 1; i <= n; i++)
            if (match[i] == 0 && dfs(i))
                matching++;
    return matching;
}

void solve() {
    int N;
    while (cin >> N) {
        vector<string> grid(N);
        for (int i = 0; i < N; i++)
            cin >> grid[i];

        vector<vector<pair<int, int> > > row_seg(N), col_seg(N);
        int row_cnt = 0, col_cnt = 0;
        vector<vector<int> > row_id(N, vector<int>(N, -1)), col_id(N, vector<int>(N, -1));

        // Filas
        For(i, 0, N) {
            int start = -1;
            For(j, 0, N) {
                if (grid[i][j] == '.') {
                    if (start == -1)
                        start = j;
                } else {
                    if (start != -1) {
                        For(k, start, j)
                            row_id[i][k] = row_cnt;
                        start = -1;
                        row_cnt++;
                    }
                }
            }
            if (start != -1) {
                For(k, start, N)
                    row_id[i][k] = row_cnt;
                row_cnt++;
            }
        }

        // Columnas
        For(j, 0, N) {
            int start = -1;
            For(i, 0, N) {
                if (grid[i][j] == '.') {
                    if (start == -1)
                        start = i;
                } else {
                    if (start != -1) {
                        For(k, start, i)
                            col_id[k][j] = col_cnt;
                        start = -1;
                        col_cnt++;
                    }
                }
            }
            if (start != -1) {
                For(k, start, N)
                    col_id[k][j] = col_cnt;
                col_cnt++;
            }
        }

        int L = row_cnt, R = col_cnt;
        n = L + R;
        G.assign(n + 1, {});
        match.assign(n + 1, 0);
        dist.assign(n + 1, INF);

        For(i, 0, N)
            For(j, 0, N)
                if (grid[i][j] == '.') {
                    int u = row_id[i][j] + 1;
                    int v = col_id[i][j] + 1 + L;
                    G[u].pb(v);
                }

        cout << hopcroft_karp() << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
