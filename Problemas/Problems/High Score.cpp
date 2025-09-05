//https://open.kattis.com/problems/highscore
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<int,int>

unordered_map<char, int> T;

string s;

int val(int c) {
    return min(26 - c, c);
}

int f(int l, int r) {
    if (r == 0)
        return 0;
    int ans = -1;
    For(i, l, r) {
        ans += val(T[s[i]]) + 1;
    }
    return ans;
}


void solve() {
    cin >> s;
    int n = (int) s.size();
    int l = 0;
    int r = 0;
    vector<Pair > A;
    while (r < n && l < n) {
        if (s[r] != 'A') {
            r++;
            l++;
        } else {
            while (r < n && s[r] == 'A')
                r++;
            A.emplace_back(l, r - 1);
            l = r;
        }
    }
    int ans = -1;
    for (const auto &c: s)
        ans += val(T[c]) + 1;

    for (const auto &e: A) {
        int pref = f(0, e.first) + e.first - 1;
        if (e.first == 0)
            pref = 0;
        int suf = f(e.second + 1, n);
        ans = min(ans, pref + 1 + suf);
        suf = suf + (n - (e.second + 1));
        ans = min(ans, 1 + suf + f(0, e.first));
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i = 0;
    for (char c = 'A'; c <= 'Z'; c++, i++)
        T[c] = i;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
