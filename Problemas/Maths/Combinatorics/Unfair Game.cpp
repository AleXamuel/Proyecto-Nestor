//https://codeforces.com/contest/2184/problem/D
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


ll ncr[35][35];

void compute() {
    ncr[0][0] = 1;
    ncr[1][0] = 1;
    ncr[1][1] = 1;
    For(i, 2, 35) {
        For(j, 0, i+1) {
            if (j == 0 || j == i)
                ncr[i][j] = 1;
            else
                ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }
}


void solve() {
    int n, k;
    cin >> n >> k;
    int msb = 31 - __builtin_clz(n);
    int ones = 1;
    ll ans = 0;
    For(i, 0, msb) {
        if (2 * ones - 1 > k) {
            int cur_ones = max(0, k + 1 - (i + 1));
            while (cur_ones <= i)
                ans += ncr[i][cur_ones++];
        }
        ones++;
    }
    cout << ans + (msb + 1 > k) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    compute();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
