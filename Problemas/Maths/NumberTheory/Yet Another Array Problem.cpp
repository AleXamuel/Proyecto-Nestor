//https://codeforces.com/contest/2167/problem/D
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


ll gcd(ll a,ll b) {
    return __gcd(a, b);
}

vector<int> primos;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            ans.push_back(i);
        if (is_prime[i] && (ll) i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for (ll &i: A)
        cin >> i;
    for (const auto &i: primos) {
        for (const auto &j: A)
            if (gcd(i, j) == 1) {
                cout << i << ln;
                return;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    primos = sieve(100);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
