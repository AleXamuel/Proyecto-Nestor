//https://vjudge.net/contest/738626#problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"

const int MAX = 1e5 + 1;

int n;
int A[MAX];

bool valid(int x) {
    For(i, 0, n-1) {
        if (A[i + 1] - A[i] > x)
            return false;
        if (A[i + 1] - A[i] == x)
            x--;
    }
    return true;
}


void solve(int caso) {
    cin >> n;
    n++;
    A[0] = 0;
    For(i, 1, n)
        cin >> A[i];
    int l = 0;
    int r = 1e9;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << "Case " << caso << ": " << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    For(i, 0, t)
        solve(i + 1);
}
