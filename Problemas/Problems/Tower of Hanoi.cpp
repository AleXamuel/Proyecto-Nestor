//https://cses.fi/problemset/task/2165/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

using Item = pair<int, int>;
vector<Item> ans;

void f(int n, int s, int t) {
    if (n == 1) {
        ans.emplace_back(s, t);
        return;
    }
    int other = 6 - s - t;
    f(n - 1, s, other);
    ans.emplace_back(s, t);
    f(n - 1, other, t);
}


void solve() {
    int n;
    cin >> n;
    f(n, 1, 3);
    cout << ans.size() << ln;
    for (const auto &[a,b]: ans)
        cout << a << " " << b << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
