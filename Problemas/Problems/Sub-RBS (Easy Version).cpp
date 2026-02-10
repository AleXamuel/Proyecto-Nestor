//https://codeforces.com/contest/2191/problem/D1
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
    int n;
    string s;
    cin >> n >> s;
    vector<int> op;
    For(i, 0, n) {
        if (s[i] == '(')
            op.push_back(i);
    }
    vector<int> suf(n);
    suf[n - 1] = 1;
    Rfor(i, n-2, 0) {
        if (s[i] == ')')
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1];
    }
    int ans = -1;
    int cnt = 0;
    int good = 0;
    For(i, 0, n) {
        if (s[i] == '(')
            cnt++;
        else {
            auto it = upper_bound(all(op), i);
            if (it == op.end()) {
                good++;
                cnt--;
                continue;
            }
            int pos = *it;
            int val = suf[pos];
            if (val >= cnt + 1) {
                int k = val - (cnt + 1);
                ans = max(ans, good * 2 + (cnt + 1) * 2 + k * 2);
            }
            good++;
            cnt--;
        }
    }
    cout << ans << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
