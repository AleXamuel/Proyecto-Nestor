//https://open.kattis.com/problems/vuk
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, sz(A)-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


const int MAX = 500;
int n, m;

char grid[MAX][MAX];

int distP[MAX][MAX];
bool visitedP[MAX][MAX];
bool visited[MAX][MAX];
Pair s, t;

bool valid(int mid) {
    For(i, 0, n)
        For(j, 0, m)
            visited[i][j] = false;
    queue<Pair > Q;
    Q.push(s);
    visited[s.first][s.second] = true;
    if (distP[s.first][s.second] < mid)
        return false;
    while (!Q.empty()) {
        Pair u = Q.front();
        Q.pop();
        int x = u.first;
        int y = u.second;
        For(i, 0, 4) {
            int curx = dx[i];
            int cury = dy[i];
            if (x + curx >= 0 && x + curx < n && y + cury >= 0 && y + cury < m) {
                if (!visited[x + curx][y + cury] && distP[x + curx][y + cury] >= mid) {
                    Q.emplace(x + curx, y + cury);
                    visited[x + curx][y + cury] = true;
                }
            }
        }
    }
    return visited[t.first][t.second];
}


void solve() {
    cin >> n >> m;
    queue<Pair > Q;
    For(i, 0, n)
        For(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == '+') {
                Q.emplace(i, j);
                distP[i][j] = 0;
                visitedP[i][j] = true;
            }
            if (grid[i][j] == 'V')
                s = {i, j};
            if (grid[i][j] == 'J')
                t = {i, j};
        }

    while (!Q.empty()) {
        Pair u = Q.front();
        Q.pop();
        int x = u.first;
        int y = u.second;
        For(i, 0, 4) {
            int curx = dx[i];
            int cury = dy[i];
            if (x + curx >= 0 && x + curx < n && y + cury >= 0 && y + cury < m) {
                if (!visitedP[x + curx][y + cury]) {
                    visitedP[x + curx][y + cury] = true;
                    distP[x + curx][y + cury] = distP[x][y] + 1;
                    Q.emplace(x + curx, y + cury);
                }
            }
        }
    }

    int l = 0;
    int r = 1e5;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
