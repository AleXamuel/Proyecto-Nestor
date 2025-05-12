//https://vjudge.net/problem/UVA-11561
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

int n, m;
char grid[50][50];
bool visited[50][50];


int solve(int i, int j) {
    if (visited[i][j])
        return 0;
    if (grid[i][j] == '#')
        return 0;
    bool cond = true;
    if (i - 1 >= 0 && grid[i - 1][j] == 'T')
        cond = false;
    if (i + 1 < n && grid[i + 1][j] == 'T')
        cond = false;
    if (j - 1 >= 0 && grid[i][j - 1] == 'T')
        cond = false;
    if (j + 1 < m && grid[i][j + 1] == 'T')
        cond = false;
    visited[i][j] = true;
    int ans = 0;
    if (grid[i][j] == 'G')
        ans++;
    if (cond) {
        if (i - 1 >= 0)
            ans += solve(i - 1, j);
        if (i + 1 < n)
            ans += solve(i + 1, j);
        if (j - 1 >= 0)
            ans += solve(i, j - 1);
        if (j + 1 < m)
            ans += solve(i, j + 1);
    }
    return ans;
}


void solve() {
    while (cin >> m >> n) {
        int x = -1;
        int y = -1;
        For(i, 0, n)
            For(j, 0, m) {
                cin >> grid[i][j];
                visited[i][j] = false;
                if (grid[i][j] == 'P') {
                    x = i;
                    y = j;
                }
            }
        cout << solve(x, y) << ln;
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
