//Leetcode 3286
#define sz(A) (int)A.size()
#define ll long long
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define Pair pair<int, int>

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct item {
    int i, j, w;
};
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
        int n = sz(grid);
        int m = sz(grid[0]);
        deque<item> Q;
        int d[n][m];
        bool visited[n][m];
        For(i, 0, n) For(j, 0, m) {
            d[i][j] = 1 << 30;
            visited[i][j] = false;
        }
        d[0][0] = 0;
        Q.push_back({0, 0, grid[0][0] == 1 ? h - 1 : h});
        while (!Q.empty()) {
            item e = Q.front();
            Q.pop_front();
            int i = e.i;
            int j = e.j;
            int w = e.w;
            if (visited[i][j])
                continue;
            visited[i][j] = true;
            For(k, 0, 4) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] &&
                    w - grid[x][y] > 0 && d[i][j] + grid[x][y] < d[x][y]) {
                    d[x][y] = d[i][j] + grid[i][j];
                    if (grid[x][y] == 0)
                        Q.push_front({x, y, w});
                    else
                        Q.push_back({x, y, w - 1});
                }
            }
        }
        return visited[n - 1][m - 1];
    }
};
