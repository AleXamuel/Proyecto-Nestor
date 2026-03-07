//https://codeforces.com/contest/2176/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

const int MOD = 998244353;
const int MAX = 2e5;
ll A[MAX];

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 0, n)
        cin >> A[i];

    map<int, map<ll, vector<int> > > adj;
    map<Pair,ll> dp;
    map<ll, vector<Pair > > H;
    For(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        H[A[a] + A[b]].emplace_back(a, b);
        adj[a][A[b]].push_back(b);
        dp[{a, b}] = 1;
    }

    for (const auto &e: H) {
        ll w = e.first;
        map<int,ll> cur_dp;
        for (const auto &[a,b]: e.second)
            cur_dp[b] += dp[{a, b}];
        for (const auto &[b,val]: cur_dp)
            for (const auto &v: adj[b][w]) {
                dp[{b, v}] += val;
                dp[{b, v}] %= MOD;
            }
    }
    ll ans = 0;
    for (const auto &e: dp) {
        ans += e.second;
        ans %= MOD;
    }
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
