//https://open.kattis.com/problems/millionairemadness
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

int n, m;
vector<vector<int> > grid;
vector<vector<bool> > visited;

void dfs(int i, int j, int x) {
    visited[i][j] = true;
    if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] - grid[i][j] <= x)
        dfs(i - 1, j, x);

    if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] - grid[i][j] <= x)
        dfs(i + 1, j, x);

    if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] - grid[i][j] <= x)
        dfs(i, j - 1, x);

    if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] - grid[i][j] <= x)
        dfs(i, j + 1, x);
}

bool valid(int x) {
    visited.assign(n, vector<bool>(m, false));
    dfs(0, 0, x);
    return visited[n - 1][m - 1];
}

void solve() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    For(i, 0, n)
        For(j, 0, m)
            cin >> grid[i][j];
    int l = 0;
    int r = 1e9;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
