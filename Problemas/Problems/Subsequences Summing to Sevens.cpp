//https://vjudge.net/problem/USACO-595
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n - 1; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    For(i, 0, n)
        cin >> a[i];

    vector<ll> prefix(n + 1, 0);
    For(i, 0, n)
        prefix[i + 1] = (prefix[i] + a[i]) % 7;

    int maxLen = 0;
    unordered_map<int, int> pos;
    For(i, 0, n + 1) {
        if (pos.count(prefix[i]))
            maxLen = max(maxLen,i - pos[prefix[i]]);
        else
            pos[prefix[i]] = i;
    }
    cout << maxLen<< ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    /*int t;
    cin >> t;
    while (t--)
        solve();*/
    solve();
    return 0;
}
