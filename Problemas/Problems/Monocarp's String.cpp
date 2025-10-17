//https://codeforces.com/contest/2145/problem/C
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
#define MOD (a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> pref(n);
    pref[0] = s[0] == 'a' ? 1 : -1;
    For(i, 1, n)
        pref[i] = pref[i - 1] + (s[i] == 'a' ? 1 : -1);

    int S = pref.back();
    int val = count(all(s), 'a') - count(all(s), 'b');
    assert(S==val);
    if (S == 0) {
        cout << 0 << ln;
        return;
    }
    unordered_map<int, int> pos;
    pos[0] = -1;
    int ans = 1 << 30;
    For(i, 0, n) {
        int req = pref[i] - S;
        if (pos.find(req) != pos.end())
            ans = min(ans, i - pos[req]);
        pos[pref[i]] = i;
    }
    cout << (ans == n ? -1 : ans) << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
