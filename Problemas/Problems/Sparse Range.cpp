//https://atcoder.jp/contests/abc444/tasks/abc444_e
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


void solve() {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> A(n);
    for (ll &i: A)
        cin >> i;
    set<ll> H;
    int r = 0;
    ll ans = 0;
    For(l, 0, n) {
        H.insert(A[l]);
        if (r == l)
            r++;
        while (r < n) {
            auto it = H.lower_bound(A[r] - d + 1);
            if (it != H.end() && *it <= A[r] + d - 1)
                break;
            H.insert(A[r]);
            r++;
        }
        H.erase(A[l]);
        ans += r - l;
    }
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
