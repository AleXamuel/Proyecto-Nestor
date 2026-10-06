#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l, r)(rng)
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rfor(i, a, b) for (ll i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define rall(A) A.rbegin(),A.rend()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<ll,ll>
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl
#define RAYA cerr << " ============================ " << endl


const int MAX = 2e5;
const int SQ = 300;
int pi[MAX], pos[MAX], A[MAX], D[MAX];
vector<int> adj[MAX];

int f(int a, int b) {
    if (a == b)
        return a;
    if (D[a] < D[b])
        swap(a, b);
    while (D[a] > D[b])
        a = pi[a];
    if (a == b)
        return a;
    while (A[a] != A[b]) {
        a = A[a];
        b = A[b];
    }
    while (pi[a] != pi[b]) {
        a = pi[a];
        b = pi[b];
    }
    return pi[a];
}

int lca(int a, int b) {
    if (a == b)
        return a;
    if (pos[a] == pos[b])
        return f(a, b);
    if (D[a] < D[b])
        swap(a, b);
    while (pos[a] != pos[b])
        a = A[a];
    return f(a, b);
}

void solve() {
    int n, q;
    cin >> n >> q;
    For(b, 1, n) {
        int a;
        cin >> a;
        a--;
        pi[b] = a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pi[0] = -1;
    pos[0] = 0;
    D[0] = 0;
    A[0] = -1;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int cur_pos = pos[u];
        int d = D[u];
        for (const auto &v: adj[u]) {
            if (v == pi[u])
                continue;
            pi[v] = u;
            D[v] = d + 1;
            if ((d + 1) % SQ == 0) {
                A[v] = u;
                pos[v] = cur_pos + 1;
            } else {
                A[v] = A[u];
                pos[v] = cur_pos;
            }
            Q.push(v);
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int l = lca(a, b);
        cout << l + 1 << ln;
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
