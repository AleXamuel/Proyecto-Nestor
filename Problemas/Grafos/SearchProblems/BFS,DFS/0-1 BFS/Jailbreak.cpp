//https://open.kattis.com/problems/jailbreak
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
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define VI vector<ll>


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const ll INF = 1e15;
const int MAX = 101;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

vector<VI > bfs(const vector<Pair > &S) {
    deque<Pair > Q;
    vector<VI > d(n, VI(m, INF));
    for (const auto &s: S) {
        if (grid[s.first][s.second] == '#') {
            d[s.first][s.second] = 1;
            Q.push_back(s);
        } else {
            d[s.first][s.second] = 0;
            Q.push_front(s);
        }
    }
    while (!Q.empty()) {
        Pair u = Q.front();
        Q.pop_front();
        int i = u.first;
        int j = u.second;
        if (visited[i][j])
            continue;
        visited[i][j] = true;
        For(_, 0, 4) {
            int x = dx[_] + i;
            int y = dy[_] + j;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] == '*')
                    continue;
                if (!visited[x][y]) {
                    if (grid[x][y] == '#' && d[i][j] + 1 < d[x][y]) {
                        Q.emplace_back(x, y);
                        d[x][y] = d[i][j] + 1;
                    } else if ((grid[x][y] != '#') && d[i][j] < d[x][y]) {
                        Q.emplace_front(x, y);
                        d[x][y] = d[i][j];
                    }
                }
            }
        }
    }
    return d;
}


void solve() {
    cin >> n >> m;
    Pair s1 = {-1, -1};
    Pair s2 = {-1, -1};
    vector<Pair > out;
    For(i, 0, n)
        For(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] != '*' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                out.emplace_back(i, j);
            visited[i][j] = false;
            if (grid[i][j] == '$') {
                if (s1.first == -1)
                    s1 = {i, j};
                else
                    s2 = {i, j};
            }
        }
    vector<VI > d1 = bfs({s1});
    For(i, 0, n)
        For(j, 0, m)
            visited[i][j] = false;
    vector<VI > d2 = bfs({s2});
    For(i, 0, n)
        For(j, 0, m)
            visited[i][j] = false;
    vector<VI > d3 = bfs(out);
    ll ans = INF;
    For(i, 0, n) {
        For(j, 0, m) {
            if (d1[i][j] == INF || d2[i][j] == INF || d3[i][j] == INF)
                continue;
            if (grid[i][j] == '#')
                ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j] - 2);
            else if (grid[i][j] != '*')
                ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j]);
        }
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
