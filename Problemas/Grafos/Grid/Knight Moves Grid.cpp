//https://cses.fi/problemset/task/3217/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"

const int MAX = 1e3;
int n;

int d[MAX][MAX];

using Edge = pair<int, int>;

void bfs() {
    queue<Edge> Q;
    Q.emplace(0, 0);
    d[0][0] = 0;
    while (!Q.empty()) {
        auto e = Q.front();
        Q.pop();
        int i = e.first;
        int j = e.second;
        if (i - 2 >= 0 && j + 1 < n && d[i - 2][j + 1] == -1) {
            d[i - 2][j + 1] = d[i][j] + 1;
            Q.emplace(i - 2, j + 1);
        }
        if (i - 2 >= 0 && j - 1 >= 0 && d[i - 2][j - 1] == -1) {
            d[i - 2][j - 1] = d[i][j] + 1;
            Q.emplace(i - 2, j - 1);
        }
        if (i + 2 < n && j + 1 < n && d[i + 2][j + 1] == -1) {
            d[i + 2][j + 1] = d[i][j] + 1;
            Q.emplace(i + 2, j + 1);
        }
        if (i + 2 < n && j - 1 >= 0 && d[i + 2][j - 1] == -1) {
            d[i + 2][j - 1] = d[i][j] + 1;
            Q.emplace(i + 2, j - 1);
        }
        if (i - 1 >= 0 && j + 2 < n && d[i - 1][j + 2] == -1) {
            d[i - 1][j + 2] = d[i][j] + 1;
            Q.emplace(i - 1, j + 2);
        }
        if (i + 1 < n && j + 2 < n && d[i + 1][j + 2] == -1) {
            d[i + 1][j + 2] = d[i][j] + 1;
            Q.emplace(i + 1, j + 2);
        }
        if (i - 1 >= 0 && j - 2 >= 0 && d[i - 1][j - 2] == -1) {
            d[i - 1][j - 2] = d[i][j] + 1;
            Q.emplace(i - 1, j - 2);
        }
        if (i + 1 < n && j - 2 >= 0 && d[i + 1][j - 2] == -1) {
            d[i + 1][j - 2] = d[i][j] + 1;
            Q.emplace(i + 1, j - 2);
        }
    }
}


void solve() {
    cin >> n;
    For(i, 0, n)
        fill(d[i], d[i] + n, -1);
    bfs();
    For(i, 0, n) {
        For(j, 0, n)
            cout << d[i][j] << " ";
        cout << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
