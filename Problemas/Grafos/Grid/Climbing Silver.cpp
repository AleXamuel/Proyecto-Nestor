//https://atcoder.jp/contests/abc443/tasks/abc443_e
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

const int MAX = 3e3 + 1;

char grid[MAX][MAX];
bool visited[MAX][MAX];
bool posible[MAX][MAX];
int n, c;

int dx[] = {-1, -1, -1};
int dy[] = {-1, 0, 1};

void bfs(int si, int sj) {
    queue<Pair > Q;
    Q.emplace(si, sj);
    visited[si][sj] = true;
    while (!Q.empty()) {
        auto e = Q.front();
        Q.pop();
        int i = e.first;
        int j = e.second;
        For(_, 0, 3) {
            int x = i + dx[_];
            int y = j + dy[_];
            if (x >= 0 && y >= 0 && y < n)
                if (!visited[x][y]) {
                    if (grid[x][y] == '#') {
                        if (posible[x][y]) {
                            if (x - 1 >= 0)
                                posible[x - 1][y] = true;
                            visited[x][y] = true;
                            Q.emplace(x, y);
                        }
                    } else {
                        visited[x][y] = true;
                        Q.emplace(x, y);
                        if (posible[x][y] && x - 1 >= 0)
                            posible[x - 1][y] = true;
                    }
                }
        }
    }
}


void solve() {
    cin >> n >> c;
    For(i, 0, n)
        For(j, 0, n) {
            cin >> grid[i][j];
            visited[i][j] = false;
            posible[i][j] = false;
        }

    For(j, 0, n)
        Rfor(i, n-1, 0) {
            posible[i][j] = true;
            if (grid[i][j] == '#')
                break;
        }
    bfs(n - 1, c - 1);
    For(i, 0, n)
        cout << visited[0][i];
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
