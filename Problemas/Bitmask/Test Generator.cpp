//https://codeforces.com/contest/2203/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rfor(i, n, k) for (ll i = n; i >= k; i--)
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

ll s, m;

bool valid(ll mid) {
    ll carry = 0;
    Rfor(i, 62, 0) {
        if (s >> i & 1)
            carry++;
        if (m >> i & 1) {
            if (mid >= carry)
                carry = 0;
            else
                carry -= mid;
        }
        carry <<= 1;
    }
    return carry <= 0;
}

void solve() {
    cin >> s >> m;
    ll j = 0;
    For(i, 0, 63)
        if (s >> i & 1) {
            j = i;
            break;
        }

    For(i, 0, 63)
        if (m >> i & 1) {
            if (i > j) {
                cout << -1 << ln;
                return;
            }
            break;
        }
    ll l = 1;
    ll r = 1e18;
    ll ans = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
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
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
