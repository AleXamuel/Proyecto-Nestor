//https://cses.fi/problemset/task/1713/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

VI factors(int n) {
    VI f;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f.push_back(x);
            n/=x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

void solve() {
    int n;
    cin >> n;
    VI f = factors(n);
    map<int, int> freq;
    for (int num : f)
        freq[num]++;

    ll ans = 1;
    for (auto [num, val] : freq) {
        ans *= val + 1;
    }

    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
