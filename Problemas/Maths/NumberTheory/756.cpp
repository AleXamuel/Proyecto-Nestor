//https://atcoder.jp/contests/abc114/tasks/abc114_d
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define PI acos(-1)
#define ln "\n"

void solve() {
    int n;
    cin >> n;

    vector<int> exp(101, 0);
    For(i, 2, n + 1) {
        int x = i;
        For(p, 2, x + 1) {
            while (x % p == 0) {
                exp[p]++;
                x /= p;
            }
        }
    }
    int cnt74 = 0, cnt24 = 0, cnt14 = 0, cnt4 = 0, cnt2 = 0;
    For(i, 2, n + 1) {
        if (exp[i] >= 74) cnt74++;
        if (exp[i] >= 24) cnt24++;
        if (exp[i] >= 14) cnt14++;
        if (exp[i] >= 4) cnt4++;
        if (exp[i] >= 2) cnt2++;
    }

    int ans = 0;
    // Tipo 1: p^74
    ans += cnt74;
    // Tipo 2: p^24 * q^2 (p != q)
    ans += cnt24 * (cnt2 - 1);
    // Tipo 3: p^14 * q^4 p != q)
    ans += cnt14 * (cnt4 - 1);
    // Tipo 4: p^4 * q^4 * r^4 (p, q, r diferentes)
    //se hace cnt4 combinado 2 porque no queremos repetir, y cnt2 - 2, porque no queremos repetir p y q
    ans += cnt4 * (cnt4 - 1) / 2 * (cnt2 - 2);

    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
