//https://vjudge.net/problem/UVA-11624
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
#define MOD (a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int MAX = 1e3;

char grid[MAX][MAX];
bool visited1[MAX][MAX];
bool visited2[MAX][MAX];
int d1[MAX][MAX];
int d2[MAX][MAX];
int n, m;


void bfs(Pair s) {
    queue<Pair > Q;
    visited1[s.first][s.second] = true;
    d1[s.first][s.second] = 0;
    Q.push(s);
    while (!Q.empty()) {
        Pair u = Q.front();
        Q.pop();
        int i = u.first;
        int j = u.second;
        For(k, 0, 4) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && !visited1[x][y] && grid[x][y] != '#') {
                Q.emplace(x, y);
                visited1[x][y] = true;
                d1[x][y] = d1[i][j] + 1;
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    Pair s;
    queue<Pair > F;
    For(i, 0, n) {
        For(j, 0, m) {
            d2[i][j] = INF(int);
            d1[i][j] = INF(int);
            visited1[i][j] = false;
            visited2[i][j] = false;
            cin >> grid[i][j];
            if (grid[i][j] == 'J')
                s = {i, j};

            if (grid[i][j] == 'F') {
                F.emplace(i, j);
                d2[i][j] = 0;
                visited2[i][j] = true;
            }
        }
    }
    bfs(s);
    while (!F.empty()) {
        Pair u = F.front();
        F.pop();
        int i = u.first;
        int j = u.second;
        For(k, 0, 4) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && !visited2[x][y] && grid[x][y] != '#') {
                F.emplace(x, y);
                visited2[x][y] = true;
                d2[x][y] = d2[i][j] + 1;
            }
        }
    }
    int ans = INF(int);
    For(i, 0, m)
        if (d1[0][i] < d2[0][i])
            ans = min(ans, d1[0][i]);

    For(i, 0, m)
        if (d1[n - 1][i] < d2[n - 1][i])
            ans = min(ans, d1[n - 1][i]);

    For(i, 0, n)
        if (d1[i][0] < d2[i][0])
            ans = min(ans, d1[i][0]);

    For(i, 0, n)
        if (d1[i][m - 1] < d2[i][m - 1])
            ans = min(ans, d1[i][m - 1]);
    if (ans == INF(int))
        cout << "IMPOSSIBLE" << ln;
    else
        cout << ans + 1 << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
