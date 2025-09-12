//https://open.kattis.com/problems/shortsell
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

const int MAX = 1e5;

ll A[MAX];

void solve() {
    int n, k;
    cin >> n >> k;
    For(i, 0, n)
        cin >> A[i];
    
    ll ans = 0;
    ll min_r = 1e18;
    Rfor(i, n-1, 0) {
        min_r = min(min_r, A[i] * 100 + i * k);
        ans = max(ans, A[i] * 100 + i * k - min_r);
    }
    
    cout << max(ans - k, 0ll) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
