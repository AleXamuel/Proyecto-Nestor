//https://codeforces.com/contest/1033/problem/A
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


const int MAX = 1e3 + 5;
bool visited[MAX][MAX];
int n;
Pair Q, K, T;
int diag1, diag2;
int dx[] = {1, -1, 1, -1, 0, 1, 0, -1};
int dy[] = {1, -1, -1, 1, 1, 0, -1, 0};

bool valid(int x, int y) {
    return x != Q.first && y != Q.second && x - y != diag1 && x + y != diag2;
}

void bfs() {
    visited[K.first][K.second] = true;
    queue<Pair > Q;
    Q.emplace(K.first, K.second);
    while (!Q.empty()) {
        auto e = Q.front();
        Q.pop();
        For(i, 0, 8) {
            int x = e.first + dx[i];
            int y = e.second + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= n && !visited[x][y] && valid(x, y)) {
                visited[x][y] = true;
                Q.emplace(x, y);
            }
        }
    }
}

void solve() {
    cin >> n >> Q.first >> Q.second >> K.first >> K.second >> T.first >> T.second;
    diag1 = Q.first - Q.second;
    diag2 = Q.first + Q.second;
    bfs();
    cout << (visited[T.first][T.second] ? "YES" : "NO") << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
