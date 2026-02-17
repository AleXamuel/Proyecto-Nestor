//https://atcoder.jp/contests/abc445/tasks/abc445_d
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
#define Pair pair<ll,ll>
#define MOD(a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


map<ll, multiset<ll> > H;
map<ll, multiset<ll> > W;
map<Pair, vector<Pair > > ans;
ll x, y;

void f(ll h, ll w) {
    if (h == 0 || w == 0)
        return;
    if (H.find(h) != H.end() && sz(H[h]) > 0) {
        ll cur_w = *H[h].begin();
        H[h].erase(H[h].find(cur_w));
        w -= cur_w;
        W[cur_w].erase(W[cur_w].find(h));
        ans[{h, cur_w}].emplace_back(x, y + w);
        f(h, w);
        return;
    }
    if (W.find(w) != W.end() && sz(W[w]) > 0) {
        ll cur_h = *W[w].begin();
        W[w].erase(W[w].find(cur_h));
        h -= cur_h;
        H[cur_h].erase(H[cur_h].find(w));
        ans[{cur_h, w}].emplace_back(x, y);
        x += cur_h;
        f(h, w);
    }
}

void solve() {
    ll h, w, n;
    cin >> h >> w >> n;
    x = y = 1;
    vector<Pair > A(n);
    For(i, 0, n) {
        Pair cur;
        cin >> cur.first >> cur.second;
        H[cur.first].insert(cur.second);
        W[cur.second].insert(cur.first);
        A[i] = cur;
    }
    f(h, w);
    For(i, 0, n) {
        cout << ans[A[i]].back().first << " " << ans[A[i]].back().second << ln;
        ans[A[i]].pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
