//https://atcoder.jp/contests/abc444/tasks/abc444_d
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
    cin >> n;
    vector<int> A(n);
    for (int &i: A)
        cin >> i;

    sort(all(A));
    vector<int> B(A[n - 1]);
    for (int &i: A) {
        i--;
        B[0] += 1;
        if (i + 1 >= sz(B))
            continue;
        B[i + 1] -= 1;
    }
    vector<ll> pref(sz(B));
    pref[0] = B[0];
    For(i, 1, sz(B))
        pref[i] = pref[i - 1] + B[i];
    // DBGA(pref);
    ll carry = 0;
    string ans;
    For(i, 0, sz(pref)) {
        pref[i] += carry;
        ans.push_back((pref[i] % 10) + '0');
        pref[i] /= 10;
        if (i == sz(pref) - 1) {
            while (pref[i] > 0) {
                ans.push_back((pref[i] % 10) + '0');
                pref[i] /= 10;
            }
        }
        carry = 0;
        carry += pref[i];
    }
    reverse(all(ans));
    cout << ans << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
