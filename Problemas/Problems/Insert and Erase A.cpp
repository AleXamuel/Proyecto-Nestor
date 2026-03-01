//https://atcoder.jp/contests/abc447/tasks/abc447_c
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;

void solve() {
    string s, t;
    cin >> s >> t;
    string a, b;
    vector<int> A, B;
    A.push_back(0);
    B.push_back(0);
    for (const auto &c: s) {
        if (c == 'A')
            A.back()++;
        else {
            a.push_back(c);
            A.push_back(0);
        }
    }

    for (const auto &c: t) {
        if (c == 'A')
            B.back()++;
        else {
            b.push_back(c);
            B.push_back(0);
        }
    }
    if (a != b) {
        cout << -1 << ln;
        return;
    }
    assert(sz(A)==sz(B));
    int n = sz(A);
    int ans = 0;
    For(i, 0, n)
        ans += abs(A[i] - B[i]);
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
