//https://codeforces.com/gym/106017/problem/I
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

ll n, k;
vector<int> A;

bool valid(ll m) {
    ll ans = 0;
    For(i, 0, n) {
        auto it = upper_bound(all(A), m - A[i]);
        if (it == A.begin())
            continue;
        --it;
        ans += it - A.begin() + 1;
    }
    return ans >= k;
}

void solve() {
    cin >> n >> k;
    A.assign(n, 0);
    for (int &i: A)
        cin >> i;
    sort(all(A));
    ll l = A[0] * 2;
    ll r = A[n - 1] * 2;
    ll ans = r;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
