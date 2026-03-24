//https://atcoder.jp/contests/abc449/tasks/abc449_d
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


void solve() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    ll ans = 0;
    for (int x = l + (l & 1); x <= r; x += 2)
        ans += max(0, min(abs(x), u) - max(-abs(x), d) + 1);
    for (int y = d + (d & 1); y <= u; y += 2)
        ans += max(0, min(abs(y) - 1, r) - max(-abs(y) + 1, l) + 1);
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
