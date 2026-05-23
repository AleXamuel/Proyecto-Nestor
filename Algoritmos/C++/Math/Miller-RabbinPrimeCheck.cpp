#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l, r)(rng);
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

ll binpow(ll a,ll b, ll mod) {
    a %= mod;
    ll ans = 1;
    while (b > 0) {
        if (b & 1ll) {
            ans = (__int128) ans * a % mod;
        }
        a = (__int128) a * a % mod;
        b >>= 1ll;
    }
    return ans;
}

bool test_base(int a,ll n,ll d, int s) {
    ll cur = binpow(a, d, n);
    For(_, 0, s) {
        ll aux = (__int128) cur * cur % n;
        if (aux == 1)
            return cur == 1 || cur == n - 1;
        cur = aux;
    }
    return false;
}

bool miller_rabin(ll n) {
    if (n <= 1)
        return false;
    if ((n & 1ll) == 0)
        return n == 2;
    ll d = n - 1;
    int s = 0;
    while ((d & 1ll) == 0) {
        s++;
        d >>= 1;
    }
    for (const auto &a: {2, 3, 5, 7, 11, 13, 17}) {
        if (n == a)
            return true;
        if (!test_base(a, n, d, s))
            return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    cout << (miller_rabin(n) ? "YES" : "NO") << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
