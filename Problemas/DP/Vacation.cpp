//https://atcoder.jp/contests/dp/tasks/dp_c
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 100001;
int A[MAXN][3];
int dp[MAXN][3];
int n;

int solve(int i, int j) {
    if (i == n - 1)
        return dp[i][j] = A[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = -1;
    if (j == 0)
        ans = max(solve(i + 1, 1), solve(i + 1, 2));
    else if (j == 1)
        ans = max(solve(i + 1, 0), solve(i + 1, 2));
    else
        ans = max(solve(i + 1, 0), solve(i + 1, 1));
    return dp[i][j] = A[i][j] + ans;
}

void solve() {
    cin >> n;
    For(i, 0, n) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }
    dp[n - 1][0] = A[n - 1][0];
    dp[n - 1][1] = A[n - 1][1];
    dp[n - 1][2] = A[n - 1][2];
    for (int i = n - 2; i >= 0; i--) {
        dp[i][0] = A[i][0] + max(dp[i + 1][1], dp[i + 1][2]);
        dp[i][1] = A[i][1] + max(dp[i + 1][0], dp[i + 1][2]);
        dp[i][2] = A[i][2] + max(dp[i + 1][0], dp[i + 1][1]);
    }
    cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
