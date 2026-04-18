//https://atcoder.jp/contests/abc453/tasks/abc453_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl;
#define RAYA cerr << " ============================ " << endl;


const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char ch[] = {'0', 'U', 'D', 'L', 'R'};

const int MAX = 1e3;
char grid[MAX][MAX];

bool visited[MAX][MAX][5];
int pi[MAX][MAX][5];

struct item {
    int i, j, dir;
};

void solve() {
    int n, m;
    cin >> n >> m;
    Pair s, t;
    For(i, 0, n) {
        For(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                s = {i, j};
            if (grid[i][j] == 'G')
                t = {i, j};
            For(k, 0, 5)
                visited[i][j][k] = false;
        }
    }
    queue<item> Q;
    Q.push({s.first, s.second, 0});
    visited[s.first][s.second][0] = true;
    pi[s.first][s.second][0] = -1;
    while (!Q.empty()) {
        item u = Q.front();
        Q.pop();
        int i = u.i;
        int j = u.j;
        int dir = u.dir;
        For(k, 1, 5) {
            int x = i + dx[k - 1];
            int y = j + dy[k - 1];
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y][k] && grid[x][y] != '#') {
                if ((grid[i][j] == 'o' && k != dir) || (grid[i][j] == 'x' && k == dir))
                    continue;
                visited[x][y][k] = true;
                pi[x][y][k] = dir;
                Q.push({x, y, k});
            }
        }
    }
    int k = -1;
    For(j, 0, 5)
        if (visited[t.first][t.second][j]) {
            k = j;
            break;
        }
    if (k == -1) {
        cout << "No" << ln;
        return;
    }
    string ans;
    int x = t.first;
    int y = t.second;
    while (pi[x][y][k] != -1) {
        int aux = k;
        ans.push_back(ch[k]);
        k = pi[x][y][k];
        if (aux == 1)
            x++;
        else if (aux == 2)
            x--;
        else if (aux == 3)
            y++;
        else
            y--;
    }
    cout << "Yes" << ln;
    reverse(all(ans));
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
