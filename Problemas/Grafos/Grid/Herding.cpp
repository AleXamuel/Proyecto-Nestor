//https://www.spoj.com/problems/HERDING/
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


const int MAX = 2e3 + 10;
char grid[MAX][MAX];
int state[MAX][MAX];
int n, m;


int dfs(int i, int j) {
    state[i][j] = 1;
    int ans = 0;
    char cur = grid[i][j];
    if (cur == 'N' && i - 1 >= 0) {
        if (state[i - 1][j] == 0)
            ans |= dfs(i - 1, j);
        else if (state[i - 1][j] == 1)
            ans = 1;
    } else if (cur == 'S' && i + 1 < n) {
        if (state[i + 1][j] == 0)
            ans |= dfs(i + 1, j);
        else if (state[i + 1][j] == 1)
            ans = 1;
    } else if (cur == 'W' && j - 1 >= 0) {
        if (state[i][j - 1] == 0)
            ans |= dfs(i, j - 1);
        else if (state[i][j - 1] == 1)
            ans = 1;
    } else if (cur == 'E' && j + 1 < m) {
        if (state[i][j + 1] == 0)
            ans |= dfs(i, j + 1);
        else if (state[i][j + 1] == 1)
            ans = 1;
    }
    state[i][j] = 2;
    return ans;
}


void solve() {
    cin >> n >> m;
    For(i, 0, n)
        For(j, 0, m) {
            cin >> grid[i][j];
            state[i][j] = 0;
        }
    int ans = 0;
    For(i, 0, n)
        For(j, 0, m)
            if (state[i][j] == 0)
                ans += dfs(i, j);


    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
