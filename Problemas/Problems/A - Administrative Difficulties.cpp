//https://codeforces.com/gym/100625/attachments
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
#define VI vector<ll>

struct spy {
    string car;
    bool inc, used;
    ll cost;
};

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, vector<ll> > carros;
    For(i, 0, n) {
        string s;
        ll c, p, k;
        cin >> s >> c >> p >> k;
        carros[s] = {c, p, k};
    }
    map<string, spy> ans;
    For(i, 0, m) {
        int t;
        string cur;
        char e;
        cin >> t >> cur >> e;
        if (e == 'p') {
            string car;
            cin >> car;
            if (ans.find(cur) == ans.end())
                ans[cur] = {car, false, true, carros[car][1]};
            else {
                if (ans[cur].inc)
                    continue;
                if (ans[cur].used) {
                    ans[cur].inc = true;
                    continue;
                }
                ans[cur].car = car;
                ans[cur].used = true;
                ans[cur].cost += carros[car][1];
            }
        } else if (e == 'a') {
            int per;
            cin >> per;
            if (ans.find(cur) == ans.end())
                ans[cur].inc = true;
            else {
                if (ans[cur].inc)
                    continue;
                if (!ans[cur].used) {
                    ans[cur].inc = true;
                    continue;
                }
                ans[cur].cost += (carros[ans[cur].car][0] * per + 99) / 100;
            }
        } else {
            int kil;
            cin >> kil;
            if (ans.find(cur) == ans.end())
                ans[cur].inc = true;
            else {
                if (ans[cur].inc)
                    continue;
                if (!ans[cur].used) {
                    ans[cur].inc = true;
                    continue;
                }
                ans[cur].cost += carros[ans[cur].car][2] * kil;
                ans[cur].used = false;
            }
        }
    }
    for (const auto &e: ans) {
        cout << e.first << " ";
        if (e.second.inc || e.second.used)
            cout << "INCONSISTENT" << ln;
        else
            cout << e.second.cost << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
