//https://vjudge.net/contest/738626#problem/J
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
    while (cin >> n && n != 0) {
        int a = 0;
        int b = 0;
        int x = 1;
        For(i, 0, 32)
            if (n >> i & 1) {
                if (x)
                    a |= 1 << i;
                else
                    b |= 1 << i;
                x ^= 1;
            }
        cout << a << " " << b << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
