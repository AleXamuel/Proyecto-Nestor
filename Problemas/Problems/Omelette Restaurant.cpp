//https://atcoder.jp/contests/abc446/tasks/abc446_c
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


void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> A(n), B(n);
    for (int &i: A)
        cin >> i;
    for (int &i: B)
        cin >> i;
    deque<int> Q;
    int j = 0;
    For(i, 0, n) {
        Q.push_back(A[i]);
        int cur = B[i];
        while (cur > 0) {
            if (Q[j] >= cur) {
                Q[j] -= cur;
                break;
            }
            cur -= Q[j];
            Q[j] = 0;
            j++;
        }
        if (i >= d) {
            Q.pop_front();
            j = max(0, j - 1);
        }
    }
    int ans = 0;
    for (const auto &i: Q)
        ans += i;
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
