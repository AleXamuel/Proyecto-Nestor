//https://vjudge.net/problem/UVA-12523
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


int A[20], I[20][2], s, n, dp[20][105];


int f(int i, int j) {
    if (i >= n) {
        if (j != 100)
            return -(1 << 25);
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = -(1 << 25);

    For(k, I[i][0], I[i][1]+1) {
        if (j + k <= 100) {
            ans = max(ans, f(i + 1, j + k) + A[i] * k);
        }
    }
    return dp[i][j] = ans;
}


void solve() {
    while (true) {
        cin >> s >> n;
        if (s == 0 && n == 0)
            break;
        memset(A, 0, sizeof(A));
        memset(I, 0, sizeof(I));
        memset(dp, -1, sizeof(dp));
        For(i, 0, s)
            For(j, 0, n) {
                int x;
                cin >> x;
                A[j] += x;
            }
        For(i, 0, n) {
            int l, r;
            cin >> l >> r;
            I[i][0] = l;
            I[i][1] = r;
        }
        int ans = (f(0, 0) + s / 2) / s;
        cout << ans / 100 << "." << setw(2) << setfill('0') << ans % 100 << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
