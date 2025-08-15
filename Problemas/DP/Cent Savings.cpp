//https://codeforces.com/gym/101482/attachments
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

const int MAX = 2e3;
const int D = 21;

int A[MAX];
int pref[MAX];
int n;

int dp[MAX][D];

int f(int val) {
    int cur = val % 10;
    if (cur < 5)
        return val - cur;
    return val + 10 - cur;
}

int f(int i, int k) {
    if (i >= n)
        return 0;
    if (k == 0)
        return f(pref[n - 1] - pref[i - 1]);

    if (dp[i][k] != -1)
        return dp[i][k];

    int ans = INF(int);
    For(j, i, n)
        ans = min(ans, f(A[i] + pref[j] - pref[i]) + f(j + 1, k - 1));
    return dp[i][k] = ans;
}

void solve() {
    int d;
    cin >> n >> d;
    For(i, 0, n)
        cin >> A[i];
    For(i, 0, n)
        For(j, 0, d+1)
            dp[i][j] = -1;
    pref[0] = A[0];
    For(i, 1, n)
        pref[i] = pref[i - 1] + A[i];
    cout << f(0, d) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
