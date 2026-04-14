//https://open.kattis.com/problems/fastestrelay
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rfor(i, a, b) for (ll i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

const int MAX = 1e3;
int A[MAX][4], n;
ll dp[MAX][16];

ll f(int i, int s) {
    if (s == 15)
        return 0;
    if (i >= n)
        return INT_MAX;
    if (dp[i][s] != -1)
        return dp[i][s];

    ll ans = f(i + 1, s);
    For(j, 0, 4)
        if ((s >> j & 1) == 0)
            ans = min(ans, f(i + 1, s | (1 << j)) + A[i][j]);
    return dp[i][s] = ans;
}

void solve() {
    cin >> n;
    For(i, 0, n)
        For(j, 0, 4)
            cin >> A[i][j];

    For(i, 0, n)
        For(j, 0, 16)
            dp[i][j] = -1;

    cout << f(0, 0) << ln;
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
