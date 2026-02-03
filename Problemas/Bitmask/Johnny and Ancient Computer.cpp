//https://codeforces.com/problemset/problem/1362/A
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
    ll s, t;
    cin >> s >> t;
    set<ll> visited;
    map<ll, int> d;
    visited.insert(s);
    d[s] = 0;
    queue<ll> Q;
    Q.push(s);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        if (u == t) {
            cout << d[t] << ln;
            return;
        }
        for (const auto &i: {1, 2, 3}) {
            ll v = u << i;
            if (v <= t && visited.find(v) == visited.end()) {
                visited.insert(v);
                d[v] = d[u] + 1;
                Q.push(v);
            }
            if ((u & ((1 << i) - 1)) == 0 && visited.find(u >> i) == visited.end()) {
                visited.insert(u >> i);
                d[u >> i] = d[u] + 1;
                Q.push(u >> i);
            }
        }
    }
    cout << -1 << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
