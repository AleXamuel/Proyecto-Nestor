//https://atcoder.jp/contests/abc442/tasks/abc442_f
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

const int MAX = 5e3 + 1;
char grid[MAX][MAX];

void solve() {
    int n;
    cin >> n;
    For(i, 0, n)
        For(j, 0, n)
            cin >> grid[i][j];

    For(j, 0, n+1) {
        grid[n][j] = '#';
        grid[j][n] = '#';
    }
    n++;
    vector<pair<vector<int>, vector<int> > > pre(n);
    For(i, 0, n) {
        vector<int> pref(n);
        pref[0] = grid[i][0] == '#';
        For(j, 1, n) {
            if (grid[i][j] == '#')
                pref[j] = pref[j - 1] + 1;
            else
                pref[j] = pref[j - 1];
        }
        vector<int> suf(n);
        suf[n - 1] = grid[i][n - 1] == '.';
        Rfor(j, n-2, 0)
            if (grid[i][j] == '.')
                suf[j] = suf[j + 1] + 1;
            else
                suf[j] = suf[j + 1];
        pre[i] = {pref, suf};
    }
    vector<ll> cur_dp(n, 0);
    vector<ll> prev_dp(n, 0);
    Rfor(i, n-2, 0) {
        Rfor(j, n-1, 0) {
            int l = pre[i].first[j];
            int r = pre[i].second[j];
            if (grid[i][j] == '#')
                l--;
            cur_dp[j] = l + r + prev_dp[j];
        }
        prev_dp.assign(n, 0);
        prev_dp[0] = cur_dp[0];
        For(j, 1, n)
            prev_dp[j] = min(prev_dp[j - 1], cur_dp[j]);
        cur_dp.assign(n, 0);
    }

    cout << *min_element(all(prev_dp)) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
