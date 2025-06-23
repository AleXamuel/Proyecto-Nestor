//https://open.kattis.com/problems/2048
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"

int grid[4][4];


void up() {
    For(i, 0, 4) {
        For(j, 0, 4) {
            int val = grid[i][j];
            if (val != 0) {
                bool next = false;
                int k = i + 1;
                while (k < 4 && grid[k][j] == 0)
                    k++;
                next = k < 4 && grid[k][j] == val;
                if (!next) {
                    grid[i][j] = 0;
                    k = i - 1;
                    while (k >= 0 && grid[k][j] == 0)
                        k--;
                    grid[k + 1][j] = val;
                    continue;
                }
                grid[i][j] = grid[k][j] = 0;
                k = i - 1;
                while (k >= 0 && grid[k][j] == 0)
                    k--;
                grid[k + 1][j] = val << 1;
            }
        }
    }
}

void down() {
    Rfor(i, 3, 0) {
        For(j, 0, 4) {
            int val = grid[i][j];
            if (val != 0) {
                bool next = false;
                int k = i - 1;
                while (k >= 0 && grid[k][j] == 0)
                    k--;
                next = k >= 0 && grid[k][j] == val;
                if (!next) {
                    grid[i][j] = 0;
                    k = i + 1;
                    while (k < 4 && grid[k][j] == 0)
                        k++;
                    grid[k - 1][j] = val;
                    continue;
                }
                grid[i][j] = grid[k][j] = 0;
                k = i + 1;
                while (k < 4 && grid[k][j] == 0)
                    k++;
                grid[k - 1][j] = val << 1;
            }
        }
    }
}

void right() {
    Rfor(j, 3, 0) {
        For(i, 0, 4) {
            int val = grid[i][j];
            if (val != 0) {
                bool next = false;
                int k = j - 1;
                while (k >= 0 && grid[i][k] == 0)
                    k--;
                next = k >= 0 && grid[i][k] == val;
                if (!next) {
                    grid[i][j] = 0;
                    k = j + 1;
                    while (k < 4 && grid[i][k] == 0)
                        k++;
                    grid[i][k - 1] = val;
                    continue;
                }
                grid[i][j] = grid[i][k] = 0;
                k = j + 1;
                while (k < 4 && grid[i][k] == 0)
                    k++;
                grid[i][k - 1] = val << 1;
            }
        }
    }
}

void left() {
    For(j, 0, 4) {
        For(i, 0, 4) {
            int val = grid[i][j];
            if (val != 0) {
                bool next = false;
                int k = j + 1;
                while (k < 4 && grid[i][k] == 0)
                    k++;
                next = k < 4 && grid[i][k] == val;
                if (!next) {
                    grid[i][j] = 0;
                    k = j - 1;
                    while (k >= 0 && grid[i][k] == 0)
                        k--;
                    grid[i][k + 1] = val;
                    continue;
                }
                grid[i][j] = grid[i][k] = 0;
                k = j - 1;
                while (k >= 0 && grid[i][k] == 0)
                    k--;
                grid[i][k + 1] = val << 1;
            }
        }
    }
}


void solve() {
    For(i, 0, 4)
        For(j, 0, 4)
            cin >> grid[i][j];
    int dir;
    cin >> dir;
    if (dir == 0)
        left();
    else if (dir == 1)
        up();
    else if (dir == 2)
        right();
    else
        down();
    For(i, 0, 4) {
        For(j, 0, 4)
            cout << grid[i][j] << " ";
        cout << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
