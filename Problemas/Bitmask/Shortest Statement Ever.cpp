//https://codeforces.com/contest/2188/problem/D
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

ll f(ll x, ll y) {
    ll q1 = 0;
    bool cond = false;
    Rfor(i, 62, 0) {
        ll a = x >> i & 1ll;
        ll b = y >> i & 1ll;
        if (a && b) {
            cond = true;
        } else if ((!a && b) || (!a && cond))
            q1 |= 1ll << i;
    }
    ll q2 = 0;
    int j = -1;
    Rfor(i, 62, 0) {
        ll a = x >> i & 1ll;
        ll b = y >> i & 1ll;
        if (a && b) {
            j = i;
            break;
        }
    }
    cond = true;
    For(i, j + 1, 63) {
        ll a = x >> i & 1ll;
        ll b = y >> i & 1ll;
        if (!a && !b && cond) {
            q2 |= 1ll << i;
            cond = false;
        }
        if (b && !cond)
            q2 |= 1ll << i;
    }
    if (abs(y - q1) < abs(y - q2))
        return q1;
    return q2;
}

void solve() {
    ll x, y;
    cin >> x >> y;
    if ((x & y) == 0) {
        cout << x << " " << y << ln;
        return;
    }
    ll a = f(x, y);
    ll b = f(y, x);
    if (abs(y - a) < abs(x - b))
        cout << x << " " << a << ln;
    else
        cout << b << " " << y << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
