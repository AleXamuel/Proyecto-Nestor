//https://cses.fi/problemset/task/1192/
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 1000;
int n, m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    Q.emplace(x, y);
    visited[x][y] = true;
    while (!Q.empty()) {
        auto e = Q.front();
        Q.pop();
        int i = e.first;
        int j = e.second;
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == '.') {
            visited[i - 1][j] = true;
            Q.emplace(i - 1, j);
        }
        if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == '.') {
            visited[i + 1][j] = true;
            Q.emplace(i + 1, j);
        }

        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == '.') {
            visited[i][j - 1] = true;
            Q.emplace(i, j - 1);
        }

        if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == '.') {
            visited[i][j + 1] = true;
            Q.emplace(i, j + 1);
        }
    }
}

void solve() {
    cin >> n >> m;
    For(i, 0, n)
        For(j, 0, m) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }

    int ans = 0;
    For(i, 0, n)
        For(j, 0, m)
            if (grid[i][j] == '.' && !visited[i][j]) {
                ans++;
                bfs(i, j);
            }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
