//https://www.spoj.com/problems/GIVEAWAY
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define dll long double
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define Vvi vector<vector<int>>
#define Vi vector<ll>
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define RAYA cerr<<"=================================="<<endl
//vector<pair<int, int> > D = {{0, 0}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
//vector<pair<int, int> > K = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; //R D U I
const int MAX = 2e5 + 2, MOD1 = 1200259153, MOD2 = 1202773163, INF = 2e9, base = 29;
//vector<int> adj[MAX], par[MAX];
int n;
vector<int> A;
const int len = (750);
vector<vector<int> > b;

void init() {
    b.assign(len,vector<int>());
    for (int i = 0; i < n; ++i)
        b[i / len].pb(A[i]);
    for (auto &arr: b)
        sort(all(arr));
}

int query(int l, int r, int x) {
    int sum = 0;
    int c_l = l / len, c_r = r / len;
    if (c_l == c_r)
        for (int i = l; i <= r; ++i)
            sum += A[i] >= x;
    else {
        for (int i = l, end = (c_l + 1) * len - 1; i <= end; ++i)
            sum += A[i]>=x;
        for (int i = c_l + 1; i <= c_r - 1; ++i)
            sum += (b[i].end()-lower_bound(all(b[i]),x));
        for (int i = c_r * len; i <= r; ++i)
            sum += A[i]>=x;
    }
    return sum;
}
void update(int idx,int x) {
    int j=idx/len;
    int y=A[idx];
    For(i,0,b[j].size())
        if(b[j][i]==y) {
            b[j][i]=x;
            break;
        }
    A[idx]=x;
    sort(all(b[j]));
}
void solve() {
    int  q;
    cin >> n;
    A.resize(n);
    For(i, 0, n)
        cin >> A[i];
    cin >> q;
    init();
    while (q--) {
        int k;
        cin >> k;
        if (k) {
            int pos, x;
            cin >> pos >> x;
            pos--;
            update(pos,x);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            cout<<query(l,r,x)<<ln;
        }
    }
}

signed main() {
    //freopen("balls.in", "r",stdin);
    //freopen("balls.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
