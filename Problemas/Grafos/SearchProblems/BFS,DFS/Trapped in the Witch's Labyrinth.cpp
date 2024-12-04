#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1)*31;
    }
};

unordered_map<pair<int, int>, vector<pair<int, int>>, pair_hash> adj;
queue<pair<int, int>> Q;
vector<vector<bool>> visited;
vector<vector<char>> grid;

const vector<int> dx = {-1, 1, 0, 0};
const vector<int> dy = {0, 0, -1, 1};

void addEdge(pair<int, int> from, pair<int, int> to) {
    adj[to].push_back(from);
}


void bfs() {
    while (!Q.empty()) {
        pair<int, int> e = Q.front();
        Q.pop();
        auto it = adj.find(e);
        if (it != adj.end()) {
            const vector<pair<int, int>> &neigh = it->second;
            for (const auto &p : neigh) {
                int x = p.first, y = p.second;
                if (!visited[x][y] && grid[x][y] != '?') {
                    visited[x][y] = true;
                    Q.push({x, y});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        grid.assign(n, vector<char>(m));
        visited.assign(n, vector<bool>(m, false));
        adj.clear();

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j];
                char c = grid[i][j];
                if (c == '?') continue;
                pair<int, int> u = {i, j};
                if (c == 'D' && i + 1 < n) addEdge(u, {i + 1, j});
                else if (c == 'U' && i - 1 >= 0) addEdge(u, {i - 1, j});
                else if (c == 'R' && j + 1 < m) addEdge(u, {i, j + 1});
                else if (c == 'L' && j - 1 >= 0) addEdge(u, {i, j - 1});
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && grid[i][0] == 'L') {
                visited[i][0] = true;
                Q.push({i, 0});
            }
            if (!visited[i][m - 1] && grid[i][m - 1] == 'R') {
                visited[i][m - 1] = true;
                Q.push({i, m - 1});
            }
        }
        for (int j = 0; j < m; j++) {
            if (!visited[0][j] && grid[0][j] == 'U') {
                visited[0][j] = true;
                Q.push({0, j});
            }
            if (!visited[n - 1][j] && grid[n - 1][j] == 'D') {
                visited[n - 1][j] = true;
                Q.push({n - 1, j});
            }
        }
        bfs();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) continue;
                bool cond = false;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
                        cond = true;
                        break;
                    }
                }
                if (cond) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
