//https://vjudge.net/problem/UVA-583
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


void solve() {
    while (true) {
        ll n;
        cin >> n;
        if (n == 0)
            break;
        cout << n << " = ";
        if (n < 0) {
            cout << "-1 x ";
            n *= -1;
        }
        for (int i = 2; (ll) i * i <= n; i++)
            while (n % i == 0) {
                n /= i;
                cout << i << (n <= 1 ? "" : " x ");
            }
        if (n > 1)
            cout << n << "";
        cout << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}

