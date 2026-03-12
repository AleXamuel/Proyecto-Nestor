//https://codeforces.com/contest/577/problem/B
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
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

const int MAX = 1e6;
const int M = 1e3;
int n, m, A[MAX];
bool dp[M][M];


bool f(int i, int j) {
    if (i >= n)
        return false;
    if (dp[i][j])
        return dp[i][j];
    if (i == n - 1)
        return dp[i][j] = true;
    f(i + 1, (j + A[i + 1]) % m);
    f(i + 1, j);
    return dp[i][j] = true;
}

void solve() {
    cin >> n >> m;
    For(i, 0, n)
        cin >> A[i];
    if (n >= m) {
        cout << "YES" << ln;
        return;
    }

    For(i, 0, n)
        For(j, 0, m)
            dp[i][j] = false;
    For(i, 0, n)
        f(i, A[i] % m);

    cout << (dp[n - 1][0] ? "YES" : "NO") << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}
