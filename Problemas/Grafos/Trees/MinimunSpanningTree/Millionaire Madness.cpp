//https://open.kattis.com/problems/millionairemadness
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (ll i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

const int MAX = 1000;

int A[MAX][MAX];
bool visited[MAX][MAX];


using Edge = pair<int, pair<int, int> >;

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, n)
        For(j, 0, m)
            cin >> A[i][j];

    set<Edge> Q;
    Q.insert({0, {0, 0}});
    while (!Q.empty()) {
        auto e = Q.begin();
        int cur_cost = e->first;
        int i = e->second.first;
        int j = e->second.second;
        Q.erase(e);
        if (visited[i][j])
            continue;
        visited[i][j] = true;
        if (i == n - 1 && j == m - 1) {
            cout << cur_cost << ln;
            return;
        }
        if (i - 1 >= 0 && !visited[i - 1][j])
            Q.insert({max(cur_cost, A[i - 1][j] - A[i][j]), {i - 1, j}});
        if (i + 1 < n && !visited[i + 1][j])
            Q.insert({max(cur_cost, A[i + 1][j] - A[i][j]), {i + 1, j}});
        if (j - 1 >= 0 && !visited[i][j - 1])
            Q.insert({max(cur_cost, A[i][j - 1] - A[i][j]), {i, j - 1}});
        if (j + 1 < m && !visited[i][j + 1])
            Q.insert({max(cur_cost, A[i][j + 1] - A[i][j]), {i, j + 1}});
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
