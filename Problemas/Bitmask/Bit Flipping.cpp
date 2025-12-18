//https://codeforces.com/contest/1659/problem/B
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> ans(n, 0);
    if (k & 1) {
        int pos = -1;
        For(i, 0, n) {
            if (s[i] == '1') {
                pos = i;
                break;
            }
        }
        if (pos == -1)
            pos = n - 1;
        ans[pos]++;
        For(i, 0, n) {
            if (i != pos)
                s[i] ^= 1;
        }
        k--;
    }
    vector<int> pos;
    For(i, 0, n)
        if (s[i] == '0')
            pos.push_back(i);
    unordered_set<int> visited;
    int last = -1;
    bool cond = false;
    For(i, 0, n) {
        if (k <= 0)
            break;
        if (s[i] == '0' && visited.find(i) == visited.end()) {
            k -= 2;
            auto it = upper_bound(all(pos), i);
            ans[i]++;
            if (it == pos.end()) {
                last = n;
                cond = true;
                ans[n - 1]++;
                break;
            }
            ans[*it]++;
            visited.insert(*it);
            last = *it + 1;
        }
    }
    if (k > 0)
        ans[n - 1] += k;
    For(i, 0, last)
        s[i] = '1';
    if (cond)
        s.back() = '0';
    cout << s << ln;
    For(i, 0, n)
        cout << ans[i] << " ";
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
