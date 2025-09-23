//https://codeforces.com/contest/2146/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<int,int>

unordered_map<int, int> H;

int findpow(int r) {
    Rfor(i, 30, 0)
        if (r >> i & 1)
            return 1 << i;

    return -1;
}

void f(int n) {
    if (n == 0)
        return;
    int j = findpow(n - 1);
    if (j == -1)
        return;
    int i = 1;
    while (j < n) {
        H[j] = j - i;
        H[j - i] = j;
        j++;
        i += 2;
    }
    n = j - i + 1;
    f(n);
}

void solve() {
    H.clear();
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    f(n);
    ll val = 0;
    For(i, 0, n) {
        val += i | H[i];
    }
    cout << val << ln;
    For(i, 0, n)
        cout << H[i] << " ";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
