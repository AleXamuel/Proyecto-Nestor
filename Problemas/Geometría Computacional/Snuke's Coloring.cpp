//https://atcoder.jp/contests/abc045/tasks/arc061_b
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

const int MAX = 1e5;
ll h, w, n;

int A[MAX][2];
set<Pair > H;

bool valid(int x, int y) {
    if (x <= 0 || x > h || y <= 0 || y > w)
        return false;

    if (x - 2 <= 0 || y + 2 > w)
        return false;
    return true;
}

int f(int x, int y) {
    int ans = 0;
    For(i, 0, 3)
        For(j, 0, 3) {
        Pair cur = {x - i, y + j};
        if (H.find(cur) != H.end())
            ans++;
    }
    return ans;
}

void solve() {
    cin >> h >> w >> n;

    For(i, 0, n) {
        cin >> A[i][0] >> A[i][1];
        H.insert({A[i][0], A[i][1]});
    }

    set<Pair > visited;
    ll ans[10];
    memset(ans, 0, sizeof(ans));
    For(i, 0, n) {
        int x = A[i][0];
        int y = A[i][1];
        For(j, 0, 3)
            For(k, 0, 3)
                if (valid(x + j, y - k)) {
                    Pair cur = {x + j, y - k};
                    if (visited.find(cur) == visited.end()) {
                        visited.insert(cur);
                        ans[f(x + j, y - k)]++;
                    }
                }
    }
    ans[0] = (h - 2) * (w - 2) - accumulate(ans, ans + 10, 0LL);
    For(i, 0, 10)
        cout << ans[i] << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
