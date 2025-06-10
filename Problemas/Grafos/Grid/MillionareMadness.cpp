//https://open.kattis.com/problems/millionairemadness

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
typedef pair<int, int> pii;

void solve() {
    int l, w;
    cin >> l >> w;

    vector<vector<int> > grid(l, vector<int>(w));
    For(i, 0, l)
        For(j, 0, w)
            cin >> grid[i][j];

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    vector<vector<int>> maxi (l, vector<int>(w, INT_MAX));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    maxi[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto [cur, pos] = pq.top();
        pq.pop();
        auto [r, c] = pos;

        if (cur > maxi[r][c])
            continue;

        if (r == l - 1 && c == w - 1) {
            cout << cur << ln;
            return;
        }

        For(i, 0, 4) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nc >= 0 && nr >= 0 && nc < w && nr < l) {
                int diff = grid[nr][nc] - grid[r][c];
                int nmaxi = max(cur, (diff > 0 ? diff : 0));

                if (nmaxi < maxi[nr][nc]) {
                    maxi[nr][nc] = nmaxi;
                    pq.push({nmaxi, {nr, nc}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
