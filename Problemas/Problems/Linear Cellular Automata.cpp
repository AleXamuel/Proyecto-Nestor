//https://vjudge.net/contest/738626#problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

int A[10], cur[40], last[40];

void solve() {
    for (int &i: A)
        cin >> i;
    memset(last, 0, sizeof(last));
    last[19] = 1;
    For(i, 0, 50) {
        memset(cur, 0, sizeof(cur));
        for (int &x: last) {
            if (x == 0)
                cout << ' ';
            else if (x == 1)
                cout << '.';
            else if (x == 2)
                cout << 'x';
            else
                cout << 'W';
        }
        cout << ln;
        cur[0] += last[0] + last[1];
        For(j, 1, 39)
            cur[j] += last[j] + last[j - 1] + last[j + 1];
        cur[39] += last[39] + last[38];
        for (int &x: cur)
            x = A[x];
        swap(cur, last);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        if (t > 0)
            cout << ln;
    }
}
