//https://codeforces.com/contest/2055/problem/C
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define MAXN 1000001

struct Point
{
    int x, y;
};

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> A(n, vector<long long>(m));
        string s;
        cin >> s;
        vector<long long> row(n, 0);
        vector<long long> col(m, 0);
        fori(i, 0, n)
            fori(j, 0, m)
        {
            cin >> A[i][j];
            row[i] += A[i][j];
            col[j] += A[i][j];
        }
        Point p = {0, 0};
        for (char c : s)
            if (c == 'D')
            {
                A[p.x][p.y] = -row[p.x];
                row[p.x] += A[p.x][p.y];
                col[p.y] += A[p.x][p.y];
                p.x++;
            }
            else
            {
                A[p.x][p.y] = -col[p.y];
                row[p.x] += A[p.x][p.y];
                col[p.y] += A[p.x][p.y];
                p.y++;
            }

        A[n - 1][m - 1] = -row[n - 1];
        fori(i, 0, n)
        {
            fori(j, 0, m)
                    cout
                << A[i][j] << " ";
            cout << ln;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    cout.flush();
    return 0;
}
