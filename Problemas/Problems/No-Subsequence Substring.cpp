//https://atcoder.jp/contests/abc452/tasks/abc452_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

bool valid(const string &a, const string &b) {
    int n = sz(a);
    if (n == 0)
        return false;
    int m = sz(b);
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j])
            i++;
        j++;
    }
    return i == n;
}

void solve() {
    string s, t;
    cin >> s >> t;
    ll n = sz(s);
    ll ans = 0;
    int r = 0;
    string cur;
    For(l, 0, n) {
        while (r < n && !valid(t, cur))
            cur.push_back(s[r++]);

        if (r >= n && !valid(t, cur))
            break;
        ans += n - r + 1;
        cur.erase(cur.begin());
    }
    cout << (n * (n + 1) / 2) - ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
