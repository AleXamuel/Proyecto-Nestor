//https://vjudge.net/problem/UVA-10401
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

int n;
vector<int> cols;

ll dp[15][15];

ll f(int i, int last) {
    if (i == n)
        return 1;

    if (last != -1 && dp[i][last] != -1)
        return dp[i][last];
    if (cols[i] != -1) {
        if (last == -1)
            return f(i + 1, cols[i]);
        if (abs(cols[i] - last) > 1)
            return dp[i][last] = f(i + 1, cols[i]);
        return dp[i][last] = 0;
    }
    ll ans = 0;
    For(j, 0, n)
        if (last == -1 || abs(last - j) > 1)
            ans += f(i + 1, j);
    if (last != -1)
        return dp[i][last] = ans;
    return ans;
}


void solve() {
    map<char, int> h;
    For(i, 1, 10)
        h[i + '0'] = i;
    for (char c = 'A'; c <= 'F'; c++)
        h[c] = c - 55;
    string s;
    while (cin >> s) {
        n = s.size();
        cols.assign(n, -1);
        For(i, 0, n)
            if (s[i] != '?')
                cols[i] = h[s[i]] - 1;
        memset(dp, -1, sizeof(dp));
        cout << f(0, -1) << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
