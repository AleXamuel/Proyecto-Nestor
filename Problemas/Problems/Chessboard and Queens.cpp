//https://cses.fi/problemset/task/1624/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

vector<vector<int> > state;
int n;

void rellenar(int x, int y) {
    For(i, 0, n) state[x][i]++;
    For(i, 0, n) if (i != x) state[i][y]++;
    int i = x + 1;
    int j = y + 1;
    while (i < n && j < n)
        state[i++][j++]++;
    i = x - 1;
    j = y - 1;
    while (i >= 0 && j >= 0)
        state[i--][j--]++;
    i = x + 1;
    j = y - 1;
    while (i < n && j >= 0)
        state[i++][j--]++;
    i = x - 1;
    j = y + 1;
    while (i >= 0 && j < n)
        state[i--][j++]++;
}

void desrellenar(int x, int y) {
    For(i, 0, n) state[x][i]--;
    For(i, 0, n) if (i != x) state[i][y]--;
    int i = x + 1;
    int j = y + 1;
    while (i < n && j < n)
        state[i++][j++]--;
    i = x - 1;
    j = y - 1;
    while (i >= 0 && j >= 0)
        state[i--][j--]--;
    i = x + 1;
    j = y - 1;
    while (i < n && j >= 0)
        state[i++][j--]--;
    i = x - 1;
    j = y + 1;
    while (i >= 0 && j < n)
        state[i--][j++]--;
}

int f(int i) {
    if (i == n)
        return 1;
    int ans = 0;
    For(j, 0, n) {
        if (state[i][j] == 0) {
            rellenar(i, j);
            ans += f(i + 1);
            desrellenar(i, j);
        }
    }
    return ans;
}


void solve() {
    n = 8;
    state.assign(n, vector<int>(n, 0));
    For(i, 0, n)
        For(j, 0, n) {
            char c;
            cin >> c;
            if (c == '*')
                state[i][j]++;
        }
    cout << f(0) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
