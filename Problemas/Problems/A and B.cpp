//https://codeforces.com/contest/2149/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define Pair pair<ll,ll>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    os << "[";
    For(i, 0, A.size()-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int n;
string s;

ll f(char c) {
    vector<ll> pref(n);
    vector<ll> suf(n);
    pref[0] = 0;
    int cnt = s[0] == c;
    For(i, 1, n) {
        if (s[i] == c) {
            cnt++;
            pref[i] = pref[i - 1];
        } else
            pref[i] = pref[i - 1] + cnt;
    }
    suf[n - 1] = 0;
    cnt = s.back() == c;
    Rfor(i, n-2, 0) {
        if (s[i] == c) {
            cnt++;
            suf[i] = suf[i + 1];
        } else
            suf[i] = suf[i + 1] + cnt;
    }
    /*DBG(c);
    DBG(pref);
    DBG(suf);
    RAYA;*/
    ll ans = 1e18;
    For(i, 0, n)
        ans = min(ans, suf[i] + pref[i]);
    return ans;
}

void solve() {
    cin >> n >> s;
    cout << min(f('a'), f('b')) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
