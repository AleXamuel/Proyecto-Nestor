//https://atcoder.jp/contests/abc451/tasks/abc451_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl

int len(ll n) {
    int ans = 0;
    while (n > 0) {
        n /= 10;
        ans++;
    }
    return ans;
}

void solve() {
    vector<ll> pot;
    queue<ll> Q;
    unordered_set<ll> visited;
    ll i = 1;
    while (i < 1e9) {
        pot.push_back(i);
        Q.push(i);
        visited.insert(i);
        i <<= 1;
    }

    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (const auto &v: pot) {
            ll cur = u;
            For(_, 0, len(v)) {
                cur *= 10;
                if (cur > 1e9)
                    break;
            }
            cur += v;
            if (cur > 1e9)
                continue;
            if (visited.find(cur) == visited.end()) {
                Q.push(cur);
                visited.insert(cur);
            }
        }
    }
    int n;
    cin >> n;
    n--;
    vector<ll> ans(all(visited));
    sort(all(ans));
    cout << ans[n] << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
