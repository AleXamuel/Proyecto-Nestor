//https://atcoder.jp/contests/abc440/tasks/abc440_c
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
#define Pair pair<int,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    vector<ll> act(2 * w);
    For(i, 0, n)
        act[i % (2 * w)] += A[i];
    vector<ll> B = act;
    for (const auto &i: act)
        B.push_back(i);
    ll sum = 0;
    For(i, 0, w)
        sum += B[i];
    ll ans = sum;
    int r = w;
    For(i, 1, 2*w) {
        sum -= B[i - 1];
        sum += B[r];
        ans = min(ans, sum);
        r++;
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
