//https://www.spoj.com/problems/KQUERY/
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l, r)(rng);
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define rall(A) A.rbegin(),A.rend()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl
#define RAYA cerr << " ============================ " << endl

struct bucket {
    int l, r;
    vector<int> cur;
};

const int SQ = 700;


void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    vector<bucket> blocks;
    int x = 0;
    for (int i = SQ - 1; i < n; i += SQ) {
        if (i == n - 1)
            x = 1;
        int l = i + 1 - SQ;
        int r = i;
        vector<int> cur;
        For(j, l, r+1) {
            cur.push_back(A[j]);
        }
        sort(all(cur));
        blocks.push_back({l, r, cur});
    }
    if (x == 0) {
        int l = (blocks.empty() ? 0 : blocks.back().r + 1);
        int r = n - 1;
        vector<int> cur;
        For(j, l, r+1) {
            cur.push_back(A[j]);
        }
        sort(all(cur));
        blocks.push_back({l, r, cur});
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r >> x;
        l--;
        r--;
        int bl = l / SQ;
        int br = r / SQ;
        if (bl == br) {
            int ans = 0;
            For(i, l, r+1) {
                if (A[i] > x)
                    ans++;
            }
            cout << ans << ln;
            continue;
        }
        int ans = 0;
        For(i, l, blocks[bl].r+1) {
            if (A[i] > x)
                ans++;
        }
        bl++;
        while (bl < br) {
            auto &cur = blocks[bl].cur;
            int pos = upper_bound(all(cur), x) - cur.begin();
            ans += sz(cur) - pos;
            bl++;
        }
        For(i, blocks[bl].l, r+1) {
            if (A[i] > x)
                ans++;
        }
        cout << ans << ln;
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w",stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
