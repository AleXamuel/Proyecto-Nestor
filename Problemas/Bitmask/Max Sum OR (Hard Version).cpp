//https://codeforces.com/contest/2146/problem/D2
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

int findMask(int x) {
    Rfor(i, 30, 0) {
        if (x >> i & 1) {
            i++;
            return (1 << i) - 1;
        }
    }
    return -1;
}


void solve() {
    int l, r;
    cin >> l >> r;
    unordered_map<int, int> H;
    for (int j = findMask(r); j >= 1; j >>= 1) {
        Rfor(i, r, l) {
            if (H.find(i) != H.end())
                continue;
            int val = i ^ j;
            if (val >= l && val <= r && H.find(val) == H.end()) {
                H[i] = val;
                H[val] = i;
            }
        }
    }
    For(i, l, r+1)
        if (H.find(i) == H.end())
            H[i] = i;
    ll sum = 0;
    For(i, l, r+1)
        sum += i | H[i];
    cout << sum << ln;
    For(i, l, r+1)
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
