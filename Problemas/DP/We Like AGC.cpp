//https://atcoder.jp/contests/abc122/tasks/abc122_d
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


const int MAX = 100;
const int MOD = 1e9 + 7;

int dp[MAX][5][5][5];
int n;


bool valid(string &s) {
    if (s.find("021") < sz(s))
        return false;
    For(i, 0, 3) {
        swap(s[i], s[i + 1]);
        if (s.find("021") < sz(s))
            return false;
        swap(s[i], s[i + 1]);
    }
    return true;
}

int f(int i, int pp, int p, int cur) {
    if (i == n)
        return 1;
    if (dp[i][pp][p][cur] != -1)
        return dp[i][pp][p][cur];
    int ans = 0;
    For(c, 0, 4) {
        string s = to_string(pp) + to_string(p) + to_string(cur) + to_string(c);
        if (valid(s)) {
            ans += f(i + 1, p, cur, c);
            ans %= MOD;
        }
    }
    return dp[i][pp][p][cur] = ans;
}


void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 4, 4, 4) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
}
