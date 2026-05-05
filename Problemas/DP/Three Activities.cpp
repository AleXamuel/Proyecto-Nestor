//https://codeforces.com/contest/1914/problem/D
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
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl;
#define RAYA cerr << " ============================ " << endl;


const int MAX = 1e5;
int A[3][MAX], n;
ll dp[MAX][1 << 3];


ll f(int i, int s) {
    if (s == (1 << 3) - 1)
        return 0;
    if (i >= n)
        return INT_MIN;
    if (dp[i][s] != -1)
        return dp[i][s];

    ll ans = f(i + 1, s);
    For(j, 0, 3)
        if ((s >> j & 1) == 0)
            ans = max(ans, f(i + 1, s | (1 << j)) + A[j][i]);
    return dp[i][s] = ans;
}

void solve() {
    cin >> n;
    For(i, 0, 3)
        For(j, 0, n)
            cin >> A[i][j];
    For(i, 0, n)
        For(j, 0, 1<<3)
            dp[i][j] = -1;

    cout << f(0, 0) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
