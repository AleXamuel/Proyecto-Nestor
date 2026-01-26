//https://codeforces.com/contest/2193/problem/E
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


const int MAX = 3e5 + 1;
vector<int> A;
int dp[MAX];
unordered_set<int> H;

vector<int> divs(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i)
                ans.push_back(n / i);
        }
    return ans;
}

int f(int n) {
    if (n == 1)
        return 0;
    if (n <= 0)
        return 1 << 30;
    if (H.find(n) != H.end())
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    int ans = 1 << 30;
    for (const auto &i: divs(n))
        if (H.find(i) != H.end())
            ans = min(ans, f(n / i) + 1);
    return dp[n] = ans;
}

void solve() {
    H.clear();
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    For(i, 0, n) {
        int x;
        cin >> x;
        H.insert(x);
    }
    int x = 0;
    if (H.find(1) != H.end()) {
        H.erase(1);
        x = 1;
    }
    if (x)
        cout << 1 << " ";
    else
        cout << -1 << " ";
    For(i, 2, n+1) {
        f(i);
        if (dp[i] == 1 << 30)
            cout << -1 << " ";
        else
            cout << dp[i] << " ";
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
