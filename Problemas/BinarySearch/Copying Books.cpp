//https://vjudge.net/problem/UVA-714
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

int n, k;
vector<int> A;

bool valid(ll mid) {
    int cnt = 1;
    ll sum = 0;
    For(i, 0, n) {
        if (A[i] + sum > mid) {
            cnt++;
            sum = A[i];
        } else
            sum += A[i];
    }
    return cnt <= k;
}

void solve() {
    cin >> n >> k;
    A.assign(n, 0);
    ll l = -1;
    ll r = 0;
    for (int &i: A) {
        cin >> i;
        r += i;
        l = max(l, (ll) i);
    }
    ll ans = r;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    ll sum = 0;
    deque<int> res;
    int cnt = 1;
    Rfor(i, n-1, 0) {
        if (sum + A[i] > ans) {
            res.push_front(-1);
            cnt++;
            sum = 0;
        }
        res.push_front(A[i]);
        sum += A[i];
    }
    int m = sz(res);
    int val = k - cnt;
    For(i, 0, m) {
        if (i + 1 < m && res[i] != -1 && res[i + 1] != -1) {
            if (val > 0) {
                val--;
                cout << res[i] << " / ";
            } else
                cout << res[i] << " ";
        } else if (res[i] == -1)
            cout << "/ ";
        else
            cout << res[i] << (i == m - 1 ? "" : " ");
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
