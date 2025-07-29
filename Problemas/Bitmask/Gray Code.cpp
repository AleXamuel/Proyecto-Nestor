//https://cses.fi/problemset/task/2205/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> prev = {0, 1};
    For(i, 1, n) {
        vector<int> cur = prev;
        for (auto it = prev.end() - 1; it != prev.begin() - 1; --it)
            cur.push_back(*it | 1 << i);
        prev = cur;
    }
    for (const auto &x: prev) {
        for (int i = n - 1; i >= 0; i--)
            if (x >> i & 1)
                cout << 1;
            else
                cout << 0;
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
