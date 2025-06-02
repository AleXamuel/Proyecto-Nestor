//https://codeforces.com/contest/1869/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
#define Pair pair<int,int>

int A[101];

void solve() {
    int n;
    cin >> n;
    bool cond = false;
    For(i, 0, n) {
        cin >> A[i];
        cond = cond || A[i] != 0;
    }
    if (!cond) {
        cout << 0 << ln;
        return;
    }
    if (n & 1) {
        if (A[0] == 0) {
            cout << 2 << ln;
            cout << 2 << " " << n << ln;
            cout << 1 << " " << n << ln;
        } else if (A[n - 1] == 0) {
            cout << 2 << ln;
            cout << 1 << " " << n - 1 << ln;
            cout << 1 << " " << n << ln;
        } else {
            cout << 4 << ln;
            cout << 1 << " " << 2 << ln;
            cout << 1 << " " << 2 << ln;
            cout << 2 << " " << n << ln;
            cout << 2 << " " << n << ln;
        }
    } else {
        cout << 2 << ln;
        cout << 1 << " " << n << ln;
        cout << 1 << " " << n << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
