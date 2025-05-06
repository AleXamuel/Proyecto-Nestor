//https://open.kattis.com/problems/stickysituation
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

const int MAXN = 20001;

ll A[MAXN];

void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    sort(A, A + n);
    For(i, 0, n-2) {
        if (A[i] + A[i + 1] > A[i + 2]) {
            cout << "possible" << ln;
            return;
        }
    }
    cout << "impossible" << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
