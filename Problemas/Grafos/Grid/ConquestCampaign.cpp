//https://open.kattis.com/problems/conquestcampaign
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
typedef pair<int, int> pii;

int r, c, n;
vector<pii> ini;
vector<vector<bool>> visited;
vector<vector<int>> d;

void bfs() {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    queue<pii> q;
    For(i, 0, ini.size()) {
        q.push(ini[i]);
        auto [row, col] = ini[i];
        visited[row][col] = true;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        For(i, 0, 4) {
            int nx = x + dr[i];
            int ny = y + dc[i];

            if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

}

void solve() {
    cin >> r >> c >> n;
    visited.assign(r, vector<bool>(c, false));
    d.assign(r, vector<int>(c, 0));
    For(i, 0, n) {
        pii pos;
        cin >> pos.first >> pos.second;
        pos.first--, pos.second--;
        ini.push_back(pos);
    }
    bfs();
    int maxi = -1;
    For(i, 0, r) {
        For(j, 0, c) {
            maxi = max(maxi, d[i][j]);
        }
    }

    cout << maxi + 1 << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
