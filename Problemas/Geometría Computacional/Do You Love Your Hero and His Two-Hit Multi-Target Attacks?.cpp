//https://codeforces.com/contest/2072/problem/E
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
#define MOD (a,b) ((a%abs(b)+abs(b))%abs(b))
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;


Pair f(int k) {
    int n = 1;
    int val = n * (n - 1) / 2;
    while (val <= k) {
        n++;
        val = n * (n - 1) / 2;
    }
    n--;
    val = n * (n - 1) / 2;
    return {n, val};
}

void solve() {
    int k;
    cin >> k;
    vector<Pair > ans;
    int x = 1;
    int x1 = 0;
    int y1 = 0;
    int x2 = -1;
    int y2 = -1;
    while (k > 0) {
        Pair e = f(k);
        k -= e.second;
        For(i, 0, e.first) {
            if (x)
                ans.emplace_back(x1++, y1);
            else
                ans.emplace_back(x2--, y2);
        }
        if (x)
            y1 -= 2;
        else
            y2 -= 2;
        x ^= 1;
    }
    cout << ans.size() << ln;
    for (const auto &i: ans)
        cout << i.first << " " << i.second << ln;
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
