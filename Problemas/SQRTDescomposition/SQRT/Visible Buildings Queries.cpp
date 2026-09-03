//https://cses.fi/problemset/task/3304/
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
};

const int SQ = 500;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;
    vector<int> pi(n);
    stack<int> Q;
    Q.push(n);
    Rfor(i, n-1, 0) {
        while (Q.top() != n && A[Q.top()] <= A[i])
            Q.pop();
        pi[i] = Q.top();
        Q.push(i);
    }
    vector<bucket> blocks;
    vector<int> cnt(n, 1);
    vector<int> pos(n, n);
    int x = 0;
    for (int i = SQ - 1; i < n; i += SQ) {
        if (i == n - 1)
            x = 1;
        int l = i + 1 - SQ;
        int r = i;
        int nx = r;
        Rfor(j, r, l) {
            if (A[nx] < A[j])
                nx = j;
            pos[j] = nx;
        }
        Rfor(j, r, l)
            if (pi[j] <= r)
                cnt[j] += cnt[pi[j]];
        blocks.push_back({l, r});
    }

    if (x == 0) {
        int l = (blocks.empty() ? 0 : blocks.back().r + 1);
        int r = n - 1;
        int nx = r;
        Rfor(i, r, l) {
            if (A[nx] < A[i])
                nx = i;
            pos[i] = nx;
            if (pi[i] <= r)
                cnt[i] += cnt[pi[i]];
        }
        blocks.push_back({l, r});
    }
    vector<int> posB(n);
    For(i, 0, n) {
        posB[i] = i / SQ;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int bl = posB[l];
        int br = posB[r];
        if (br == bl) {
            int ans = 0;
            while (l <= r) {
                l = pi[l];
                ans++;
            }
            cout << ans << ln;
            continue;
        }
        int ans = 0;
        while (true) {
            int curb = posB[l]; //indice del bucket actual
            if (blocks[curb].r > r) {
                while (l <= r) {
                    l = pi[l];
                    ans++;
                }
                break;
            }
            ans += cnt[l]; //cantidad de elementos alcanzables desde l en el bucket de l
            int cur = pos[l]; //ultimo alcanzable del bucket de l
            if (pi[cur] > r)
                break;
            l = pi[cur];
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
