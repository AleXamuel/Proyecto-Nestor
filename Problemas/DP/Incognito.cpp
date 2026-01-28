//https://open.kattis.com/problems/incognito
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
#define VI vector<ll>


void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> H;
    For(i, 0, n) {
        string a, b;
        cin >> a >> b;
        H[b]++;
    }
    vector<int> A;
    for (const auto &[k,v]: H)
        A.push_back(v);
    int N = sz(A);
    vector<ll> dp(N + 1, 0);
    dp[0] = 1;
    For(i, 0, sz(A))
        Rfor(j, i+1, 1)
            dp[j] += dp[j - 1] * A[i];
    cout << accumulate(all(dp), 0ll) - dp[0] << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
