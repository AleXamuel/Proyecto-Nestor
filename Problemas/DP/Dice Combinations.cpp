//https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"


int A[] = {1, 2, 3, 4, 5, 6};
const int MOD = 1e9 + 7;
unordered_map<int, int> dp;

int solve(int n, int sum) {
    if (sum > n)
        return 0;
    if (sum == n)
        return 1;
    if (dp.find(sum) != dp.end())
        return dp[sum];
    int ans = 0;
    for (int &i: A)
        ans = (ans % MOD + solve(n, sum + i) % MOD) % MOD;
    return dp[sum] = ans;
}


void solve() {
    int n;
    cin >> n;
    cout << solve(n, 0) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
