//http://cses.fi/problemset/task/1692/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pcc = pair<char, char>;
 
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);
 
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
 
vector<int> deBruijn(int k, int n) {
    vector<int> result;
    vector<int> a(n * k, 0);
 
    function<void(int, int)> rec = [&](int t, int p) {
        if (t > n) {
            if (n % p == 0) {
                for (int i = 1; i <= p; i++) {
                    result.push_back(a[i]);
                }
            }
        } else {
            a[t] = a[t - p];
            rec(t + 1, p);
            for (a[t] = a[t - p] + 1; a[t] < k; a[t]++) {
                rec(t + 1, t);
            }
        }
    };
 
    rec(1, 1);
    return result;
}
 
 
void solve() {
    int n;
    cin >> n;
    VI cycle = deBruijn(2, n);
    for (int x: cycle)
        cout << x;
 
    For(i, 0, n - 1)
        cout << cycle[i];
 
    cout << ln;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
